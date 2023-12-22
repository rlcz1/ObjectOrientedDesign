#ifndef _INT_SET_H_
#define _INT_SET_H_

#include <assert.h>
#include <functional>
#include <iostream>

class IntSet {
 public:
  explicit IntSet(int capacity);
  IntSet(const IntSet& int_set);
  int capacity() const;
  int size() const;
  const int * elements() const;
  void Add(int value);
  void Add(const IntSet& int_set);
  void Map(std::function<int(int)> f);
  bool ForAll(std::function<bool(int)> f);
 private:
  int capacity_;  // 현재 intSet객체에 저장된 원소의 개수
  int size_;  // 현재 IntSET객체에 저장된 원소의 개수
  int *elements_;  // 현재 IntSEt객체에 저장된 원소들
};

#endif  // _INT_SET_H
