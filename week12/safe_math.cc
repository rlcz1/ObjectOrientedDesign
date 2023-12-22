#include <string>

#include "safe_math.h"
#include "divide_by_zero_exception.h"

/*
invalid operation에 대해 exception을 발생하는 class 구현
a. Add, Sub, Mul: overflow 발생 시 std::overflow_error exception 발생
  I. 메시지: Integer overflow occurs in [operation].
  II. e.g Integer overflow occurs in 2147483647 + 1.
  III. e.g Integer overflow occurs in -2147483647 – 1.
  IV. e.g Integer overflow occurs in -2147483647 * 2.
b. Div, Mod: divisor가 0일 시, DivideByZeroException exception 발생
  I. 메시지: Divide-by-zero exception occurs in [operation].
  II. e.g Divide-by-zero exception occurs in 1243 / 0.
  III. e.g Divide-by-zero exception occurs in 1243 % 0.
*/

int SafeMath::Add(int x, int y) {
  if (x > 0 && y > 0) {
    if (x > kMax - y) {
      std::string operation =
        "Integer overflow occurs in "
        + std::to_string(x)
        + " + "
        + std::to_string(y)
        + ".";
      throw std::overflow_error(operation.c_str());
      // throw WrapAroundForMax(x, y);
    }
  } else if (x < 0 && y < 0) {
    if (x < kMin - y) {
      std::string operation =
        "Integer overflow occurs in "
        + std::to_string(x)
        + " + "
        + std::to_string(y)
        + ".";
      throw std::overflow_error(operation.c_str());
      // throw WrapAroundForMin(x, y);
    }
  }
  return x + y;
}

int SafeMath::Sub(int x, int y) {
  if (x > 0 && y < 0) {
    if (x > kMax + y) {
      std::string operation =
        "Integer overflow occurs in "
        + std::to_string(x)
        + " - "
        + std::to_string(y)
        + ".";
      throw std::overflow_error(operation.c_str());
      // throw WrapAroundForMax(x, y);
    }
  } else if (x < 0 && y > 0) {
    if (x < kMin + y) {
      std::string operation =
        "Integer overflow occurs in "
        + std::to_string(x)
        + " - "
        + std::to_string(y)
        + ".";
      throw std::overflow_error(operation.c_str());
      // throw WrapAroundForMin(x, y);
    }
  }
  return x - y;
}

int SafeMath::Mul(int x, int y) {
  if (x > 0 && y > 0) {
    if (x > kMax / y) {
      std::string operation =
        "Integer overflow occurs in "
        + std::to_string(x)
        + " * "
        + std::to_string(y)
        + ".";
      throw std::overflow_error(operation.c_str());
      // throw WrapAroundForMax(x, y);
    }
  } else if (x < 0 && y < 0) {
    if (x < kMin / y) {
      std::string operation =
        "Integer overflow occurs in "
        + std::to_string(x)
        + " * "
        + std::to_string(y)
        + ".";
      throw std::overflow_error(operation.c_str());
      // throw WrapAroundForMin(x, y);
    }
  }
  return x * y;
}

int SafeMath::Div(int x, int y) {
  if (y == 0) {
    std::string operation =
      "Divide-by-zero exception occurs in "
      + std::to_string(x)
      + " / 0.";
    throw DivideByZeroException(operation.c_str());
  }
  return x / y;
}

int SafeMath::Mod(int x, int y) {
  if (y == 0) {
    std::string operation =
      "Divide-by-zero exception occurs in "
      + std::to_string(x)
      + " % 0.";
    throw DivideByZeroException(operation.c_str());
  }
  return x % y;
}
