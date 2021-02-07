#ifndef HERMIT_H
#define HERMIT_H

#include "func.h"

typedef struct {
  double x;
  double y;
  double der;
}point_t;

point_t* CreateTableByCheb(double lbord, double rbord, int numOfPoints, double(*func)(double), double(*der)(double));

double HermitCalc(point_t* points, int numOfPoints, double x);

#endif /*HERMIT_H*/