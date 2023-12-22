#include "gtest/gtest.h"
#include "int_accumulator.h"
#include "float_accumulator.h"

class IntAccTest : public ::testing::Test {
 public:
  IntAccTest() : accumulator_(3) {}
 protected:
  void SetUp() override {}
  void TearDown() override {}
  int_accumulator::Accumulator accumulator_;
};

// int - ADD
TEST_F(IntAccTest, IntAccAddTest1) {
  accumulator_.Add(1);
  EXPECT_EQ(accumulator_.acc(), 4);
}
TEST_F(IntAccTest, IntAccAddTest2) {
  accumulator_.Add(2);
  EXPECT_EQ(accumulator_.acc(), 5);
}
TEST_F(IntAccTest, IntAccAddTest3) {
  accumulator_.Add(3);
  EXPECT_EQ(accumulator_.acc(), 6);
}

// int - SUB
TEST_F(IntAccTest, IntAccSubTest1) {
  accumulator_.Sub(1);
  EXPECT_EQ(accumulator_.acc(), 2);
}
TEST_F(IntAccTest, IntAccSubTest2) {
  accumulator_.Sub(2);
  EXPECT_EQ(accumulator_.acc(), 1);
}
TEST_F(IntAccTest, IntAccSubTest3) {
  accumulator_.Sub(3);
  EXPECT_EQ(accumulator_.acc(), 0);
}

// int - Mult
TEST_F(IntAccTest, IntAccMultTest1) {
  accumulator_.Mult(1);
  EXPECT_EQ(accumulator_.acc(), 3);
}
TEST_F(IntAccTest, IntAccMultTest2) {
  accumulator_.Mult(2);
  EXPECT_EQ(accumulator_.acc(), 6);
}
TEST_F(IntAccTest, IntAccMultTest3) {
  accumulator_.Mult(3);
  EXPECT_EQ(accumulator_.acc(), 9);
}

// int - DIV
TEST_F(IntAccTest, IntAccDivTest1) {
  ASSERT_DEATH(accumulator_.Div(0), "Divide-by-zero");
}
TEST_F(IntAccTest, IntAccDivTest2) {
  accumulator_.Div(1);
  EXPECT_EQ(accumulator_.acc(), 3);
}
TEST_F(IntAccTest, IntAccDivTest3) {
  accumulator_.Div(3);
  EXPECT_EQ(accumulator_.acc(), 1);
}

class FloatAccTest : public ::testing::Test {
 public:
  FloatAccTest() : accumulator_(3) {}
 protected:
  void SetUp() override {}
  void TearDown() override {}
  float_accumulator::Accumulator accumulator_;
};

// float - ADD
TEST_F(FloatAccTest, FloatAccAddTest1) {
  accumulator_.Add(1);
  EXPECT_FLOAT_EQ(accumulator_.acc(), 4);
}
TEST_F(FloatAccTest, FloatAccAddTest2) {
  accumulator_.Add(2);
  EXPECT_FLOAT_EQ(accumulator_.acc(), 5);
}
TEST_F(FloatAccTest, FloatAccAddTest3) {
  accumulator_.Add(3);
  EXPECT_FLOAT_EQ(accumulator_.acc(), 6);
}

// float - SUB
TEST_F(FloatAccTest, FloatAccSubTest1) {
  accumulator_.Sub(1);
  EXPECT_FLOAT_EQ(accumulator_.acc(), 2);
}
TEST_F(FloatAccTest, FloatAccSubTest2) {
  accumulator_.Sub(2);
  EXPECT_FLOAT_EQ(accumulator_.acc(), 1);
}
TEST_F(FloatAccTest, FloatAccSubTest3) {
  accumulator_.Sub(3);
  EXPECT_FLOAT_EQ(accumulator_.acc(), 0);
}

// float - Mult
TEST_F(FloatAccTest, FloatAccMultTest1) {
  accumulator_.Mult(1);
  EXPECT_FLOAT_EQ(accumulator_.acc(), 3);
}
TEST_F(FloatAccTest, FloatAccMultTest2) {
  accumulator_.Mult(2);
  EXPECT_FLOAT_EQ(accumulator_.acc(), 6);
}
TEST_F(FloatAccTest, FloatAccMultTest3) {
  accumulator_.Mult(3);
  EXPECT_FLOAT_EQ(accumulator_.acc(), 9);
}

// float - DIV
TEST_F(FloatAccTest, FloatAccDivTest1) {
  ASSERT_DEATH(accumulator_.Div(0), "Divide-by-zero");
}
TEST_F(FloatAccTest, FloatAccDivTest2) {
  accumulator_.Div(1);
  EXPECT_FLOAT_EQ(accumulator_.acc(), 3);
}
TEST_F(FloatAccTest, FloatAccDivTest3) {
  accumulator_.Div(3);
  EXPECT_FLOAT_EQ(accumulator_.acc(), 1);
}
