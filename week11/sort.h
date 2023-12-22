#include <iostream>
#include <utility>

template <typename T, typename N>

void Sort(typename T::iterator begin, typename T::iterator end) {
  for (typename T::iterator i = begin; i != end; i++) {
    for (typename T::iterator j = i; j != end; j++) {
      if ( N() (*j, *i) ) {
        std::swap(*i, *j);
      }
    }
  }
}
