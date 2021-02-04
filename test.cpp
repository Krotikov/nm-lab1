#include "test.h"

double DeltaAbs(double x, double y) {
  return fabs(x - y);
}

double FindMax(double* arr, int len) {
  double max = 0;
  for (int i = 0; i < len; ++i) {
    if (max < arr[i])
      max = arr[i];
  }
  return max;
}

std::string FileName(std::string str, int symb) {
  char sym = symb + '0';
  std::string res = str + sym + ".txt";
  return res;
}

void TestErr(int numOfPoints) {
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

  points = CreateTableByCheb(lbord, rbord, numOfPoints);
  ypoint.open(FileName(s1, numOfPoints));
  xpoint.open(FileName(s2, numOfPoints));

  for (int i = 0; i < numOfPoints - 1; ++i) {
    midPoints[i] = points[i + 1].x - points[i].x;
  }

  for (int i = 0; i < numOfPoints; ++i) {
    xpoint << points[i].x << " "; //saving grid points
    ypoint << points[i].y << " ";

    deltaInPoint[i] = fabs(HermitCalc(points, numOfPoints, points[i].x) - Func(points[i].x));
    if (i != numOfPoints - 1)
      deltaInMid[i] = fabs(HermitCalc(points, numOfPoints, midPoints[i]) - Func(midPoints[i]));
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


void TestHermit(int numOfPoints) {
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

  points = CreateTableByCheb(lbord, rbord, numOfPoints);
  fVal.open(FileName(s1, numOfPoints));
  fRes.open(FileName(s2, numOfPoints));
  fDelta.open(FileName(s3, numOfPoints));

  for (double x = lbord; x <= rbord; x += dx) {
    res = HermitCalc(points, numOfPoints, x);
    delta = Func(x) - res;
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

