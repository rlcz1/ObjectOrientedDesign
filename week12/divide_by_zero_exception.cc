#include "divide_by_zero_exception.h"

DivideByZeroException::DivideByZeroException(const char *what)
: runtime_error(what) {}
