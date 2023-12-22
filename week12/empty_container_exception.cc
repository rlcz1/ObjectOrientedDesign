#include "empty_container_exception.h"

// 비어있는 상황에서 pop하는 경우, EmptyContainerException을 던진다.
// 1. 메세지 : This [container] is empty.
// 2. e.g This vector is empty.
// 3. e.g This list is empty.

// Invalid index에 접근하는 경우, std::out_of_range 예외를 던진다.
// 1. 메세지 : The index is [index], but the size is [size].
// 2. e.g The index is 3, but the size is 3.

EmptyContainerException::EmptyContainerException(const char *what)
: runtime_error(what) {}
