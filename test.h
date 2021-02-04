
#ifndef TEST_H
#define TEST_H

#include "func.h"
#include <fstream>
#include <string>

#define LBORD -2
#define RBORD 2
#define DELTA 1e-2

typedef enum {
  ERROR = -1,
  OK
}ERR_STATUS;

void TestHermit(int numOfPoints);

void TestErr(int numOfPoints);

#endif /*TEST_H*/