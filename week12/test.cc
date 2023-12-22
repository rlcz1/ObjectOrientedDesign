#include "gtest/gtest.h"
#include "stack.h"
#include "queue.h"
#include "vector.h"
#include "list.h"
#include "empty_container_exception.h"
#include "divide_by_zero_exception.h"
#include "safe_math.h"

class ListTest : public ::testing::Test {
 protected:
  List<int> list_;
  void SetUp() override {}
  void TearDown() override {}
 public :
  ListTest() : list_() {}
};

TEST_F(ListTest, EmptyContainerException1) {
  try {
    list_.PopBack();
  } catch (const EmptyContainerException& e) {
    // EXPECT_EQ(e.what(), "This list is empty.");
    EXPECT_EQ(e.what(), std::string("This list is empty."));
    // EXPECT_STREQ(e.what(), "This list is empty.");
  }
}

TEST_F(ListTest, EmptyContainerException2) {
  try {
    list_.PopFront();
  } catch (const EmptyContainerException& e) {
    EXPECT_STREQ(e.what(), "This list is empty.");
  }
}

TEST_F(ListTest, OutOfRangeException1) {
  try {
    list_.At(5);
  } catch (const std::out_of_range& e) {
    EXPECT_STREQ(e.what(), "The index is 5, but the size is 0.");
  }
}

class VectorTest : public ::testing::Test {
 protected:
  Vector<int> vector_;
  void SetUp() override {}
  void TearDown() override {}
 public :
  VectorTest() : vector_(4) {}
};

TEST_F(VectorTest, EmptyContainerException1) {
  try {
    vector_.PopBack();
  } catch (const EmptyContainerException& e) {
    EXPECT_STREQ(e.what(), "This vector is empty.");
  }
}

TEST_F(VectorTest, OutOfRangeException1) {
  try {
    vector_[5];
  } catch (const std::out_of_range& e) {
    EXPECT_STREQ(e.what(), "The index is 5, but the size is 0.");
  }
}

class SafeMathTest : public ::testing::Test {
 protected:
  SafeMath safe_math_;
  void SetUp() override {}
  void TearDown() override {}
 public :
  SafeMathTest() : safe_math_() {}
};

TEST_F(SafeMathTest, AddOverflowException1) {
  try {
    safe_math_.Add(2147483647, 1);
  } catch (const std::overflow_error& e) {
    EXPECT_STREQ(e.what(), "Integer overflow occurs in 2147483647 + 1.");
  }
}

TEST_F(SafeMathTest, AddOverflowException2) {
  try {
    safe_math_.Add(-2147483647, -1);
  } catch (const std::overflow_error& e) {
    EXPECT_EQ(e.what(),
    std::string("Integer overflow occurs in -2147483647 + -1."));
  }
}

TEST_F(SafeMathTest, AddOverflowException3) {
  try {
    safe_math_.Add(2147483647, 2);
  } catch (const std::overflow_error& e) {
    EXPECT_STREQ(e.what(), "Integer overflow occurs in 2147483647 + 2.");
  }
}

TEST_F(SafeMathTest, SubOverflowException1) {
  try {
    safe_math_.Sub(2147483647, -1);
  } catch (const std::overflow_error& e) {
    EXPECT_STREQ(e.what(), "I");
  }
}

TEST_F(SafeMathTest, SubOverflowException2) {
  try {
    safe_math_.Sub(-2147483647, 1);
  } catch (const std::overflow_error& e) {
    EXPECT_STREQ(e.what(), "Integer overflow occurs in -2147483647 - 1.");
  }
}

TEST_F(SafeMathTest, MulOverflowException1) {
  try {
    safe_math_.Mul(-2147483647, 2);
  } catch (const std::overflow_error& e) {
    EXPECT_STREQ(e.what(), "Integer overflow occurs in -2147483647 * 2.");
  }
}

TEST_F(SafeMathTest, MulOverflowException2) {
  try {
    safe_math_.Mul(2147483647, 2);
  } catch (const std::overflow_error& e) {
    EXPECT_STREQ(e.what(), "Integer overflow occurs in 2147483647 * 2.");
  }
}

TEST_F(SafeMathTest, DivideByZeroException1) {
  try {
    safe_math_.Div(1, 0);
  } catch (const DivideByZeroException& e) {
    EXPECT_STREQ(e.what(), "Divide-by-zero exception occurs in 1 / 0.");
  }
}

TEST_F(SafeMathTest, DivideByZeroException2) {
  try {
    safe_math_.Mod(1, 0);
  } catch (const DivideByZeroException& e) {
    EXPECT_STREQ(e.what(), "Divide-by-zero exception occurs in 1 % 0.");
  }
}

TEST_F(SafeMathTest, DivideByZeroException3) {
  try {
    safe_math_.Div(1234, 0);
  } catch (const DivideByZeroException& e) {
    EXPECT_STREQ(e.what(), "Divide-by-zero exception occurs in 1234 / 0.");
  }
}

TEST_F(SafeMathTest, DivideByZeroException4) {
  try {
    safe_math_.Mod(1234, 0);
  } catch (const DivideByZeroException& e) {
    EXPECT_STREQ(e.what(), "Divide-by-zero exception occurs in 1234 % 0.");
  }
}
