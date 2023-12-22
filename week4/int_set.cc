#include "int_set.h"

IntSet::IntSet(int capacity) {
  capacity_ = capacity;
  size_ = 0;
  elements_ = new int[capacity];
}

IntSet::IntSet(const IntSet &int_set) {
  capacity_ = int_set.capacity_;
  size_ = int_set.size_;
  elements_ = new int[capacity_];

  for (int i = 0; i < size_; i++) {
    elements_[i] = int_set.elements_[i];
  }
}

int IntSet::capacity() const {
  return capacity_;
}
int IntSet::size() const {
  return size_;
}

const int *IntSet::elements() const {
    return elements_;
}

void IntSet::Add(int value) {
  assert(size_ < capacity_ && "Exceeded capacity");

  for (int i = 0; i < size_; i++) {  // 중복 체크
    if (elements_[i] == value) return;
  }

  elements_[size_++] = value;
}

void IntSet::Add(const IntSet &int_set) {
  for (int i = 0; i < int_set.size_; i++) {
    int value = int_set.elements_[i];

    bool flag = false;
    for (int j = 0; j < size_; j++) {
      if (elements_[j] == value) {
        flag = true;
        break;
      }
    }

    if (flag == false) {
      assert(size_ < capacity_ && "Exceeded capacity");
      elements_[size_++] = value;
    }
  }
}

void IntSet::Map(std::function<int(int)> f) {
  for (int i = 0; i < size_; i++) {
    elements_[i] = f(elements_[i]);
  }
}

bool IntSet::ForAll(std::function<bool(int)> f) {
  for (int i = 0; i < size_; i++) {
    if (!f(elements_[i])) {
      return false;
    }
  }
  return true;
}
