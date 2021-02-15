
#ifndef TEST_H
#define TEST_H

#include "hermit.h"
#include <fstream>
#include <string>

#define LBORD -2
#define RBORD 2
#define NUM_MIN 2
#define NUM_MAX 50
#define DELTA 1e-2

typedef enum {
  ERROR = -1,
  OK
}ERR_STATUS;

void TestHermit(int numOfPoints, double(*func)(double), double(*der)(double));

void TestErr(int numOfPoints, double(*func)(double), double(*der)(double));

void TestErrFromNumNodes(double(*func)(double), double(*der)(double));

#endif /*TEST_H*/