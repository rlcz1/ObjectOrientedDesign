#include "util.h"

// 두 정수를 더한 값을 반환
int Util::Add(int x, int y) {
    return x + y;
}

// 두 정수를 뺸 값을 반환
int Util::Sub(int x, int y) {
    return x - y;
}

// 두 정수를 곱한 값을 반환
int Util::Mult(int x, int y) {
    return x * y;
}

// 두 정수를 나눈 값을 반환
int Util::Div(int x, int y) {
    assert(y != 0 && "Divide-by-zero");
    return x / y;
}
