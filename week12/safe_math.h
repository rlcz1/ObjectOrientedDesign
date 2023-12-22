#ifndef _SAFE_MATH_H_
#define _SAFE_MATH_H_

#include <limits>
#include <stdexcept>

class SafeMath {
 public:
  static int Add(int x, int y);  // overflow
  static int Sub(int x, int y);  // overflow
  static int Mul(int x, int y);  // overflow
  static int Div(int x, int y);  // divide-by-zero
  static int Mod(int x, int y);  // divide-by-zero

 private:
  static const int kMax = std::numeric_limits<int>::max();
  static const int kMin = std::numeric_limits<int>::lowest();

  // static int WrapAroundForMax(int x, int y);
  // static int WrapAroundForMin(int x, int y);
};

#endif  // _SAFE_MATH_H_
