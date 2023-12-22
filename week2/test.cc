#include "gtest/gtest.h"
#include "util.h"

class UtilTest : public ::testing::Test {
 protected :
  void SetUp() override {}
  void TearDown() override {}
  Util u;
};

TEST_F(UtilTest, UtilAddTest1) {
  EXPECT_EQ(u.Add(1, 3), 4);
}
TEST_F(UtilTest, UtilAddTest2) {
  EXPECT_EQ(u.Add(55, 45), 100);
}
TEST_F(UtilTest, UtilAddTest3) {
  EXPECT_EQ(u.Add(3, 1), 4);
}

TEST_F(UtilTest, UtilDivTest1) {
  ASSERT_DEATH(u.Div(1, 0), "Divide-by-zero");
}
TEST_F(UtilTest, UtilDivTest2) {
  EXPECT_EQ(u.Div(6, 3), 2);
}
TEST_F(UtilTest, UtilDivTest3) {
  EXPECT_EQ(u.Div(6, 2), 3);
}

TEST_F(UtilTest, UtilSubTest1) {
  EXPECT_EQ(u.Sub(3, 1), 2);
}
TEST_F(UtilTest, UtilSubTest2) {
  EXPECT_EQ(u.Sub(1, 3), -2);
}
TEST_F(UtilTest, UtilSubTest3) {
  EXPECT_EQ(u.Sub(3, 3), 0);
}

TEST_F(UtilTest, UtilMultTest1) {
  EXPECT_EQ(u.Mult(1, 3), 3);
}
TEST_F(UtilTest, UtilMultTest2) {
  EXPECT_EQ(u.Mult(3, 1), 3);
}
TEST_F(UtilTest, UtilMultTest3) {
  EXPECT_EQ(u.Mult(3, 3), 9);
}
