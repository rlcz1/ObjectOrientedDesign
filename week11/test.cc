#include <array>
#include <vector>
#include <list>
#include <deque>

#include "gtest/gtest.h"

#include "sort.h"


class IntIncreasingOrder {
 public:
  int operator()(const int& x, const int& y) {
    if (x < y) {
      return 1;
    } else {
      return 0;
    }
  }
};

class IntDecreasingOrder {
 public:
  int operator()(const int& x, const int& y) {
    if (x > y) {
      return 1;
    } else {
      return 0;
    }
  }
};

class ArraySortTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
  }

  std::array<int, 8> arr_;
};

TEST_F(ArraySortTest, IntIncreasingOrder) {
  arr_ = {1, 3, 5, 2, 6, 7, 4, 0};
  Sort<std::array<int, 8>, IntIncreasingOrder>(arr_.begin(), arr_.end());

  EXPECT_EQ(0, arr_[0]);
  EXPECT_EQ(1, arr_[1]);
  EXPECT_EQ(2, arr_[2]);
  EXPECT_EQ(3, arr_[3]);
  EXPECT_EQ(4, arr_[4]);
  EXPECT_EQ(5, arr_[5]);
  EXPECT_EQ(6, arr_[6]);
  EXPECT_EQ(7, arr_[7]);
}
TEST_F(ArraySortTest, IntIncreasingOrder2) {
  arr_ = {0, 1, 2, 3, 7, 6, 5, 4};
  Sort<std::array<int, 8>, IntIncreasingOrder>(arr_.begin(), arr_.end());

  EXPECT_EQ(0, arr_[0]);
  EXPECT_EQ(1, arr_[1]);
  EXPECT_EQ(2, arr_[2]);
  EXPECT_EQ(3, arr_[3]);
  EXPECT_EQ(4, arr_[4]);
  EXPECT_EQ(5, arr_[5]);
  EXPECT_EQ(6, arr_[6]);
  EXPECT_EQ(7, arr_[7]);
}

TEST_F(ArraySortTest, IntDecreasingOrder) {
  arr_ = {1, 3, 5, 2, 6, 7, 4, 0};
  Sort<std::array<int, 8>, IntDecreasingOrder>(arr_.begin(), arr_.end());

  EXPECT_EQ(7, arr_[0]);
  EXPECT_EQ(6, arr_[1]);
  EXPECT_EQ(5, arr_[2]);
  EXPECT_EQ(4, arr_[3]);
  EXPECT_EQ(3, arr_[4]);
  EXPECT_EQ(2, arr_[5]);
  EXPECT_EQ(1, arr_[6]);
  EXPECT_EQ(0, arr_[7]);
}
TEST_F(ArraySortTest, IntDecreasingOrder2) {
  arr_ = {0, 1, 2, 3, 7, 6, 5, 4};
  Sort<std::array<int, 8>, IntDecreasingOrder>(arr_.begin(), arr_.end());

  EXPECT_EQ(7, arr_[0]);
  EXPECT_EQ(6, arr_[1]);
  EXPECT_EQ(5, arr_[2]);
  EXPECT_EQ(4, arr_[3]);
  EXPECT_EQ(3, arr_[4]);
  EXPECT_EQ(2, arr_[5]);
  EXPECT_EQ(1, arr_[6]);
  EXPECT_EQ(0, arr_[7]);
}

class VectorSortTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
  }

  std::vector<int> vec_;
};

TEST_F(VectorSortTest, IntIncreasingOrder) {
  vec_ = {1, 3, 5, 2, 6, 7, 4, 0};
  Sort<std::vector<int>, IntIncreasingOrder>(vec_.begin(), vec_.end());

  EXPECT_EQ(0, vec_[0]);
  EXPECT_EQ(1, vec_[1]);
  EXPECT_EQ(2, vec_[2]);
  EXPECT_EQ(3, vec_[3]);
  EXPECT_EQ(4, vec_[4]);
  EXPECT_EQ(5, vec_[5]);
  EXPECT_EQ(6, vec_[6]);
  EXPECT_EQ(7, vec_[7]);
}
TEST_F(VectorSortTest, IntIncreasingOrder2) {
  vec_ = {0, 1, 2, 3, 7, 6, 5, 4};
  Sort<std::vector<int>, IntIncreasingOrder>(vec_.begin(), vec_.end());

  EXPECT_EQ(0, vec_[0]);
  EXPECT_EQ(1, vec_[1]);
  EXPECT_EQ(2, vec_[2]);
  EXPECT_EQ(3, vec_[3]);
  EXPECT_EQ(4, vec_[4]);
  EXPECT_EQ(5, vec_[5]);
  EXPECT_EQ(6, vec_[6]);
  EXPECT_EQ(7, vec_[7]);
}

TEST_F(VectorSortTest, IntDecreasingOrder) {
  vec_ = {1, 3, 5, 2, 6, 7, 4, 0};
  Sort<std::vector<int>, IntDecreasingOrder>(vec_.begin(), vec_.end());

  EXPECT_EQ(7, vec_[0]);
  EXPECT_EQ(6, vec_[1]);
  EXPECT_EQ(5, vec_[2]);
  EXPECT_EQ(4, vec_[3]);
  EXPECT_EQ(3, vec_[4]);
  EXPECT_EQ(2, vec_[5]);
  EXPECT_EQ(1, vec_[6]);
  EXPECT_EQ(0, vec_[7]);
}
TEST_F(VectorSortTest, IntDecreasingOrder2) {
  vec_ = {0, 1, 2, 3, 7, 6, 5, 4};
  Sort<std::vector<int>, IntDecreasingOrder>(vec_.begin(), vec_.end());

  EXPECT_EQ(7, vec_[0]);
  EXPECT_EQ(6, vec_[1]);
  EXPECT_EQ(5, vec_[2]);
  EXPECT_EQ(4, vec_[3]);
  EXPECT_EQ(3, vec_[4]);
  EXPECT_EQ(2, vec_[5]);
  EXPECT_EQ(1, vec_[6]);
  EXPECT_EQ(0, vec_[7]);
}

class ListSortTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
  }

  std::list<int> lst_;
};

TEST_F(ListSortTest, IntIncreasingOrder) {
  lst_ = {1, 3, 5, 2, 6, 7, 4, 0};
  Sort<std::list<int>, IntIncreasingOrder>(lst_.begin(), lst_.end());

  EXPECT_EQ(0, lst_.front());
  lst_.pop_front();
  EXPECT_EQ(1, lst_.front());
  lst_.pop_front();
  EXPECT_EQ(2, lst_.front());
  lst_.pop_front();
  EXPECT_EQ(3, lst_.front());
  lst_.pop_front();
  EXPECT_EQ(4, lst_.front());
  lst_.pop_front();
  EXPECT_EQ(5, lst_.front());
  lst_.pop_front();
  EXPECT_EQ(6, lst_.front());
  lst_.pop_front();
  EXPECT_EQ(7, lst_.front());
  lst_.pop_front();
}
TEST_F(ListSortTest, IntIncreasingOrder2) {
  lst_ = {0, 1, 2, 3, 7, 6, 5, 4};
  Sort<std::list<int>, IntIncreasingOrder>(lst_.begin(), lst_.end());

  EXPECT_EQ(0, lst_.front());
  lst_.pop_front();
  EXPECT_EQ(1, lst_.front());
  lst_.pop_front();
  EXPECT_EQ(2, lst_.front());
  lst_.pop_front();
  EXPECT_EQ(3, lst_.front());
  lst_.pop_front();
  EXPECT_EQ(4, lst_.front());
  lst_.pop_front();
  EXPECT_EQ(5, lst_.front());
  lst_.pop_front();
  EXPECT_EQ(6, lst_.front());
  lst_.pop_front();
  EXPECT_EQ(7, lst_.front());
  lst_.pop_front();
}

TEST_F(ListSortTest, IntDecreasingOrder) {
  lst_ = {1, 3, 5, 2, 6, 7, 4, 0};
  Sort<std::list<int>, IntDecreasingOrder>(lst_.begin(), lst_.end());

  EXPECT_EQ(7, lst_.front());
  lst_.pop_front();
  EXPECT_EQ(6, lst_.front());
  lst_.pop_front();
  EXPECT_EQ(5, lst_.front());
  lst_.pop_front();
  EXPECT_EQ(4, lst_.front());
  lst_.pop_front();
  EXPECT_EQ(3, lst_.front());
  lst_.pop_front();
  EXPECT_EQ(2, lst_.front());
  lst_.pop_front();
  EXPECT_EQ(1, lst_.front());
  lst_.pop_front();
  EXPECT_EQ(0, lst_.front());
  lst_.pop_front();
}
TEST_F(ListSortTest, IntDecreasingOrder2) {
  lst_ = {0, 1, 2, 3, 7, 6, 5, 4};
  Sort<std::list<int>, IntDecreasingOrder>(lst_.begin(), lst_.end());

  EXPECT_EQ(7, lst_.front());
  lst_.pop_front();
  EXPECT_EQ(6, lst_.front());
  lst_.pop_front();
  EXPECT_EQ(5, lst_.front());
  lst_.pop_front();
  EXPECT_EQ(4, lst_.front());
  lst_.pop_front();
  EXPECT_EQ(3, lst_.front());
  lst_.pop_front();
  EXPECT_EQ(2, lst_.front());
  lst_.pop_front();
  EXPECT_EQ(1, lst_.front());
  lst_.pop_front();
  EXPECT_EQ(0, lst_.front());
  lst_.pop_front();
}

class DequeSortTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
  }

  std::deque<int> deq_;
};

TEST_F(DequeSortTest, IntIncreasingOrder) {
  deq_ = {1, 3, 5, 2, 6, 7, 4, 0};
  Sort<std::deque<int>, IntIncreasingOrder>(deq_.begin(), deq_.end());

  EXPECT_EQ(0, deq_[0]);
  EXPECT_EQ(1, deq_[1]);
  EXPECT_EQ(2, deq_[2]);
  EXPECT_EQ(3, deq_[3]);
  EXPECT_EQ(4, deq_[4]);
  EXPECT_EQ(5, deq_[5]);
  EXPECT_EQ(6, deq_[6]);
  EXPECT_EQ(7, deq_[7]);
}
TEST_F(DequeSortTest, IntIncreasingOrder2) {
  deq_ = {0, 1, 2, 3, 7, 6, 5, 4};
  Sort<std::deque<int>, IntIncreasingOrder>(deq_.begin(), deq_.end());

  EXPECT_EQ(0, deq_[0]);
  EXPECT_EQ(1, deq_[1]);
  EXPECT_EQ(2, deq_[2]);
  EXPECT_EQ(3, deq_[3]);
  EXPECT_EQ(4, deq_[4]);
  EXPECT_EQ(5, deq_[5]);
  EXPECT_EQ(6, deq_[6]);
  EXPECT_EQ(7, deq_[7]);
}

TEST_F(DequeSortTest, IntDecreasingOrder) {
  deq_ = {1, 3, 5, 2, 6, 7, 4, 0};
  Sort<std::deque<int>, IntDecreasingOrder>(deq_.begin(), deq_.end());

  EXPECT_EQ(7, deq_[0]);
  EXPECT_EQ(6, deq_[1]);
  EXPECT_EQ(5, deq_[2]);
  EXPECT_EQ(4, deq_[3]);
  EXPECT_EQ(3, deq_[4]);
  EXPECT_EQ(2, deq_[5]);
  EXPECT_EQ(1, deq_[6]);
  EXPECT_EQ(0, deq_[7]);
}
TEST_F(DequeSortTest, IntDecreasingOrder2) {
  deq_ = {0, 1, 2, 3, 7, 6, 5, 4};
  Sort<std::deque<int>, IntDecreasingOrder>(deq_.begin(), deq_.end());

  EXPECT_EQ(7, deq_[0]);
  EXPECT_EQ(6, deq_[1]);
  EXPECT_EQ(5, deq_[2]);
  EXPECT_EQ(4, deq_[3]);
  EXPECT_EQ(3, deq_[4]);
  EXPECT_EQ(2, deq_[5]);
  EXPECT_EQ(1, deq_[6]);
  EXPECT_EQ(0, deq_[7]);
}
