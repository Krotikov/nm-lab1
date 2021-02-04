#include "test.h"

using std::cout;
using std::endl;

int main() {
  int numOfPoints1 = 3;
  int numOfPoints2 = 4;
  int numOfPoints3 = 6;

  cout << "For 3 points:" << endl;
  TestErr(numOfPoints1);
  TestHermit(numOfPoints1);

  cout << "For 4 points:" << endl;
  TestErr(numOfPoints2);
  TestHermit(numOfPoints2);

  cout << "For 6 points:" << endl;
  TestErr(numOfPoints3);
  TestHermit(numOfPoints3);

  return OK;
}