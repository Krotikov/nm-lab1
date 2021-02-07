#include "test.h"

double FindMax(double* arr, int len) {
  double max = 0;
  for (int i = 0; i < len; ++i) {
    if (max < arr[i])
      max = arr[i];
  }
  return max;
}

std::string FileName(std::string str, int symb, double(*func)(double)) {
  char sym = symb + '0';
  std::string res = str + sym + ".txt";
  std::string beg;
  if (func == &Func)
    beg = "Func/";
  else if (func == &FuncBreak)
    beg = "FuncBreak/";
  else
    beg = "noname/";
  res = beg + res;
  return res;
}

void TestErr(int numOfPoints, double(*func)(double), double(*der)(double)) {
  std::ofstream ypoint;
  std::ofstream xpoint;
  std::string s1 = "ypoint", s2 = "xpoint";
  point_t* points;
  double* deltaInPoint = (double*)malloc(sizeof(double) * numOfPoints);
  double* midPoints = (double*)malloc(sizeof(double) * (numOfPoints - 1));
  double* deltaInMid = (double*)malloc(sizeof(double) * (numOfPoints - 1));
  double lbord = LBORD;
  double rbord = RBORD;
  double maxInPoint = 0, maxInMid = 0;

  points = CreateTableByCheb(lbord, rbord, numOfPoints, func, der);
  ypoint.open(FileName(s1, numOfPoints, func));
  xpoint.open(FileName(s2, numOfPoints, func));

  for (int i = 0; i < numOfPoints - 1; ++i) {
    midPoints[i] = points[i + 1].x - points[i].x;
  }

  for (int i = 0; i < numOfPoints; ++i) {
    xpoint << points[i].x << " "; //saving grid points
    ypoint << points[i].y << " ";

    deltaInPoint[i] = fabs(HermitCalc(points, numOfPoints, points[i].x) - func(points[i].x));
    if (i != numOfPoints - 1)
      deltaInMid[i] = fabs(HermitCalc(points, numOfPoints, midPoints[i]) - func(midPoints[i]));
  }

  maxInPoint = FindMax(deltaInPoint, numOfPoints);
  maxInMid = FindMax(deltaInMid, numOfPoints - 1);

  std::cout << "Max delta in point:" << maxInPoint << std::endl;
  std::cout <<"Max delta in mid:" << maxInMid << std::endl;

  free(deltaInPoint);
  free(midPoints);
  free(deltaInMid);
  free(points);

  xpoint.close();
  ypoint.close();

  return;
}


void TestHermit(int numOfPoints, double(*func)(double), double(*der)(double)) {
  std::ofstream fVal;
  std::ofstream fRes;
  std::ofstream fDelta;
  std::string s1 = "test_val", s2 = "test_res", s3 = "test_delta";
  double dx = DELTA;
  double lbord = LBORD;
  double rbord = RBORD;
  double res = 0;
  double delta = 0;
  point_t* points;

  points = CreateTableByCheb(lbord, rbord, numOfPoints, func, der);
  fVal.open(FileName(s1, numOfPoints, func));
  fRes.open(FileName(s2, numOfPoints, func));
  fDelta.open(FileName(s3, numOfPoints, func));

  for (double x = lbord; x <= rbord; x += dx) {
    res = HermitCalc(points, numOfPoints, x);
    delta = func(x) - res;
    fDelta << delta << " ";
    fVal << x << " ";
    fRes << res << " ";
  }

  fVal.close();
  fRes.close();
  fDelta.close();

  free(points);
  
  return;
}

void TestErrFromNumNodes(double(*func)(double), double(*der)(double)) {
  double lbord = LBORD;
  double rbord = RBORD;
  double delta = 0;
  point_t* points = nullptr;
  std::ofstream fVal, fRes;

  fVal.open("test_EFNNVal.txt");
  fRes.open("test_EFNNRes.txt");

  for (int i = NUM_MIN; i <= NUM_MAX; ++i) {
    points = CreateTableByCheb(lbord, rbord, i, func, der);
    delta = fabs(HermitCalc(points, i, lbord) - func(lbord));
    fRes << delta << " ";
    fVal << i << " ";
    free(points);
  }

  fVal.close();
  fRes.close();

  return;
}

