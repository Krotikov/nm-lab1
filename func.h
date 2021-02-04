#ifndef FUNC_H
#define FUNC_H

#define _USE_MATH_DEFINES
#include <iostream>
#include <cctype>
#include <cmath>

typedef struct {
  double x;
  double y;
  double der;
}point_t;

double Func(double x);

double FuncDer(double x);

point_t* CreateTableByCheb(double lbord, double rbord, int numOfPoints);

double HermitCalc(point_t* points, int numOfPoints, double x);


#endif /*FUNC_H*/