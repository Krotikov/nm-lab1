#include "test.h"

using std::cout;
using std::endl;

//TODO: graph max_delat(numOfPoints)

int main() {
  int numOfPoints1 = 3;
  int numOfPoints2 = 4;
  int numOfPoints3 = 6;

  cout << "For normal function:" << endl;
  cout << "For 3 points:" << endl;
  TestErr(numOfPoints1, &Func, &FuncDer);
  TestHermit(numOfPoints1, &Func, &FuncDer);

  cout << "For 4 points:" << endl;
  TestErr(numOfPoints2, &Func, &FuncDer);
  TestHermit(numOfPoints2, &Func, &FuncDer);

  cout << "For 6 points:" << endl;
  TestErr(numOfPoints3, &Func, &FuncDer);
  TestHermit(numOfPoints3, &Func, &FuncDer);

  //--------------------------------------------
  cout << "For function with break:" << endl;
  cout << "For 3 points:" << endl;
  TestErr(numOfPoints1, &FuncBreak, &FuncBreakDer);
  TestHermit(numOfPoints1, &FuncBreak, &FuncBreakDer);

  cout << "For 4 points:" << endl;
  TestErr(numOfPoints2, &FuncBreak, &FuncBreakDer);
  TestHermit(numOfPoints2, &FuncBreak, &FuncBreakDer);

  cout << "For 6 points:" << endl;
  TestErr(numOfPoints3, &FuncBreak, &FuncBreakDer);
  TestHermit(numOfPoints3, &FuncBreak, &FuncBreakDer);

  //For function with break
  TestErrFromNumNodes(&FuncBreak, &FuncBreakDer);

  return OK;
}