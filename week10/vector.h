#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <cassert>
#include <cstddef>

template <typename T>
class Vector {
 public:
  explicit Vector(std::size_t capacity) : capacity_(capacity), size_(0) {
    elements_ = new T[capacity_];
  }
  Vector(const Vector& vector)
  : capacity_(vector.capacity_), size_(vector.size_) {
    elements_ = new T[vector.capacity_];

    for (int i = 0; i < size_; i++) {
      elements_[i] = vector.elements_[i];
    }
  }
  virtual ~Vector() {
    delete[] elements_;
  }
  void operator=(const Vector& vector) {
    delete[] elements_;

    capacity_ = vector.capacity_;
    size_ = vector.size_;

    elements_ = new T[capacity_];
    for (int i = 0; i < size_; i++) {
      elements_[i] = vector.elements_[i];
    }
  }
  T& operator[](const int index) {
    assert((size_ > index && index >= 0) && "Out-of-bound");

    return elements_[index];
  }
  int size() const {
    return size_;
  }
  int capacity() const {
    return capacity_;
  }
  void PushBack(T elem) {
    if (size_ >= capacity_) {
      capacity_ += 4;

      T* temp = new T[capacity_];
      for (int i = 0; i < size_; i++) {
        temp[i] = elements_[i];
      }

      delete[] elements_;
      elements_ = temp;
    }

    elements_[size_++] = elem;
  }
  void PopBack() {
    assert(size_ > 0 && "Out-of-bound");

    size_--;
  }
  bool IsEmpty() const {
    return size_ == 0;
  }
 private :
  T* elements_;
  int capacity_;
  int size_;
};

#endif  // _VECTOR_H_
