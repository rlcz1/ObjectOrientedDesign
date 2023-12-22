#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>
#include <cassert>

#include "empty_container_exception.h"

template <typename T>
class List {
 public:
  List() : size_(0), head_(nullptr) {}
  List(const List& list) : size_(list.size_) {
    if (head_ != nullptr) {
      head_ = new Elem{list.head_->value, nullptr};

      Elem* h = head_;
      Elem* n = list.head_->next;
      while (n != nullptr) {
        h->next = new Elem{n->value, nullptr};
        h = h->next;

        n = n->next;
      }
    } else {
      head_ = nullptr;
    }
  }
  virtual ~List() {
    while (head_ != nullptr) {
      Elem* h = head_;
      head_ = head_->next;

      delete h;
    }
  }
  void operator=(const List& list) {
    while (head_ != nullptr) {
      Elem* h = head_;
      head_ = head_->next;

      delete h;
    }

    if (head_ != nullptr) {
      head_ = new Elem{list.head_->value, nullptr};

      Elem* h = head_;
      Elem* n = list.head_->next;
      while (n != nullptr) {
        h->next = new Elem{n->value, nullptr};
        h = h->next;

        n = n->next;
      }
    } else {
      head_ = nullptr;
    }
    size_ = list.size_;
  }
  int size() const {
    return size_;
  }
  void PushBack(T elem) {
    Elem* e = new Elem{elem, nullptr};
      if (head_ != nullptr) {
        Elem* h = head_;
        while (h->next != nullptr) {
          h = h->next;
        }
        h->next = e;
      } else {
        head_ = e;
    }

    size_++;
  }
  void PushFront(T elem) {
    Elem* e = new Elem{elem, head_};
    head_ = e;

    size_++;
  }
  void PopBack() {
    // assert(head_ != nullptr && "Out-of-bound");
    if (head_ == nullptr) {
      throw EmptyContainerException("This list is empty.");
    }


    if (head_->next == nullptr) {  // 1개
      // delete head_;
      head_ = nullptr;
    } else {
      Elem* h = head_;
      while (h->next->next != nullptr) {
        h = h->next;
      }
      delete h->next;
      h->next = nullptr;
    }
    size_--;
  }
  void PopFront() {
    // assert(head_ != nullptr && "Out-of-bound");
    if (head_ == nullptr) {
      throw EmptyContainerException("This list is empty.");
    }

    Elem* h = head_;
    head_ = head_->next;
    delete h;

    size_--;
  }
  T& At(int index) {
    // assert((index >= 0 && index < size_) && "Out-of-bound");
    if (index < 0 || index >= size_) {
      throw std::out_of_range(
        "The index is "
        + std::to_string(index)
        + ", but the size is "
        + std::to_string(size_) + ".");
    }

    Elem* h = head_;

    for (int i = 0; i < index; i++) {
      h = h->next;
    }
    return h->value;
  }
  bool IsEmpty() const {
    if (size_ <= 0) {
      return true;
    }
    return false;
  }
 private :
  struct Elem {
    T value;
    Elem* next;
  };
  Elem* head_;
  int size_;
};

#endif  // _LIST_H_
