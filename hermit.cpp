#include "hermit.h"

double* ChebPolyRoots(int numOfPoints) {
  double* roots = (double*)malloc(sizeof(double) * numOfPoints);
  for (int i = 0; i < numOfPoints; ++i) {
    roots[i] = cos(M_PI * (2 * i + 1) / (2 * (numOfPoints + 1)));
  }

  return roots;
}

point_t* CreateTableByCheb(double lbord, double rbord, int numOfPoints, double(*func)(double), double(*der)(double)) {
  point_t* points = (point_t*)malloc(sizeof(point_t) * numOfPoints);
  double* roots = ChebPolyRoots(numOfPoints);

  for (int i = 0; i < numOfPoints; ++i) {
    points[i].x = (lbord + rbord) / 2 + (rbord - lbord) / 2 * roots[i];
    points[i].y = func(points[i].x);
    points[i].der = der(points[i].x);
  }

  return points;
}


double HermitCalc(point_t* points, int numOfPoints, double x) {
  double sum = 0;
  double prod = 1;
  double res = 0;

  for (int j = 0; j < numOfPoints; ++j) {
    for (int k = 0; k < numOfPoints; ++k) {
      if (k == j)
        continue;
      sum += (x - points[j].x) / (points[j].x - points[k].x);
      prod *= (x - points[k].x) / (points[j].x - points[k].x) * (x - points[k].x) / (points[j].x - points[k].x);
    }
    res += ((x - points[j].x) * points[j].der + (1 - 2 * sum) * points[j].y) * prod;
    sum = 0;
    prod = 1;
  }

  return res;
}