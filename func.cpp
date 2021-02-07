#include "func.h"

double Func(double x) {
  double res = x * x + 4 * sin(x) - 2;
  return res;
}

double FuncDer(double x) {
  double res = 2 * x + 4 * cos(x);
  return res;
}

double FuncBreak(double x) {
  double res = fabs(x * x + 4 * (sin(x) - sin(0.5)) - 0.25) + (4 * sin(0.5) - 1.75);
  return res;
}

double FuncBreakDer(double x) {
  double res = ((x * x + 4 * (sin(x) - sin(0.5)) - 0.25) + (4 * sin(0.5) - 1.75) / fabs(x * x + 4 * (sin(x) - sin(0.5)) - 0.25) + (4 * sin(0.5) - 1.75)) * (2 * x + 4 * cos(x));
  return res;
}