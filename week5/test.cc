#include "gtest/gtest.h"
#include "int_set.h"

class IntSetTest : public ::testing::Test {
 public:
  IntSetTest() : int_set(3) {}
 protected:
  void SetUp() override {}
  void TearDown() override {}
  IntSet int_set;
};

// Intset
TEST_F(IntSetTest, IntSetTest1) {
  IntSet int_set_copy = IntSet(int_set);

  EXPECT_EQ(int_set.size(), int_set_copy.size());
}
TEST_F(IntSetTest, IntSetTest2) {
  IntSet int_set_copy = IntSet(int_set);

  EXPECT_EQ(int_set.capacity(), int_set_copy.capacity());
}
TEST_F(IntSetTest, IntSetTest3) {
  IntSet int_set_copy = IntSet(int_set);

  EXPECT_EQ(int_set.elements()[0], int_set_copy.elements()[0]);
}


// ADD
TEST_F(IntSetTest, IntSetAddTest1) {
  int_set.Add(1);

  EXPECT_EQ(int_set.size(), 1);
  EXPECT_EQ(int_set.capacity(), 3);
  EXPECT_EQ(int_set.elements()[0], 1);
}
TEST_F(IntSetTest, IntSetAddTest2) {
  int_set.Add(2);

  EXPECT_EQ(int_set.size(), 1);
  EXPECT_EQ(int_set.capacity(), 3);
  EXPECT_EQ(int_set.elements()[0], 2);
}
TEST_F(IntSetTest, IntSetAddTest3) {
  int_set.Add(2);
  int_set.Add(3);

  EXPECT_EQ(int_set.size(), 2);
  EXPECT_EQ(int_set.capacity(), 3);
  EXPECT_EQ(int_set.elements()[0], 2);
}

// AddIntSet
TEST_F(IntSetTest, IntSetAddIntSetTest1) {
  IntSet temp(3);
  temp.Add(2);
  temp.Add(3);

  int_set.Add(temp);

  EXPECT_EQ(int_set.size(), 2);
}
TEST_F(IntSetTest, IntSetAddIntSetTest2) {
  int_set.Add(3);

  IntSet temp(3);
  temp.Add(2);
  temp.Add(3);

  int_set.Add(temp);

  EXPECT_EQ(int_set.size(), 2);
}
TEST_F(IntSetTest, IntSetAddIntSetTest3) {
  int_set.Add(3);

  IntSet temp(3);
  temp.Add(1);
  temp.Add(2);
  temp.Add(3);

  int_set.Add(temp);

  EXPECT_EQ(int_set.size(), 3);
}

// Map
TEST_F(IntSetTest, IntSetMapTest1) {
  int_set.Add(1);
  int_set.Add(2);

  int_set.Map([](int i) {return i * i;});

  EXPECT_EQ(int_set.elements()[0], 1);
}
TEST_F(IntSetTest, IntSetMapTest2) {
  int_set.Add(1);
  int_set.Add(2);

  int_set.Map([](int i) {return i * i;});

  EXPECT_EQ(int_set.elements()[1], 4);
}
TEST_F(IntSetTest, IntSetMapTest3) {
  int_set.Add(1);
  int_set.Add(2);

  int_set.Map([](int i) {return i * 2;});

  EXPECT_EQ(int_set.elements()[0], 2);
  EXPECT_EQ(int_set.elements()[1], 4);
}

// ForAll
TEST_F(IntSetTest, IntSetForAllTest1) {
  int_set.Add(1);
  int_set.Add(20);

  bool result = int_set.ForAll([](int i) { return i > 10; });

  EXPECT_EQ(result, false);
}
TEST_F(IntSetTest, IntSetForAllTest2) {
  int_set.Add(10);
  int_set.Add(20);

  bool result = int_set.ForAll([](int i) { return i > 5; });

  EXPECT_EQ(result, true);
}
TEST_F(IntSetTest, IntSetForAllTest3) {
  int_set.Add(100);
  int_set.Add(20);

  bool result = int_set.ForAll([](int i) { return i > 50; });

  EXPECT_EQ(result, false);
}

// operator
TEST_F(IntSetTest, IntSetOperatorTest1) {
  int_set.Add(3);

  EXPECT_EQ(int_set[0], 3);
}
TEST_F(IntSetTest, IntSetOperatorTest2) {
  ASSERT_DEATH({
    int_set.Add(1);
    int_set[0];
    int_set[1];
  }, "Out-of-bound");
}
TEST_F(IntSetTest, IntSetOperatorTest3) {
  int_set.Add(3);
  int_set.Add(3);

  EXPECT_EQ(int_set[0], 3);
  EXPECT_EQ(int_set.size(), 1);
}
TEST_F(IntSetTest, forallfuncest2) {
IntSet intset1(1);

intset1.Add(0);
intset1.Add(0);

  EXPECT_TRUE(intset1.ForAll([](int v) {return v == 0;}));
}

// add - update
TEST_F(IntSetTest, IntSetAdd2Test1) {
  int_set.Add(1);
  int_set.Add(2);
  int_set.Add(3);
  int_set.Add(4);

  EXPECT_EQ(int_set.size(), 4);
  EXPECT_EQ(int_set.capacity(), 7);
  EXPECT_EQ(int_set.elements()[0], 1);
  EXPECT_EQ(int_set.elements()[1], 2);
  EXPECT_EQ(int_set.elements()[2], 3);
  EXPECT_EQ(int_set.elements()[3], 4);
}
TEST_F(IntSetTest, IntSetAdd2Test2) {
  int_set.Add(1);
  int_set.Add(2);
  int_set.Add(3);
  int_set.Add(4);
  int_set.Add(5);
  int_set.Add(6);
  int_set.Add(7);
  int_set.Add(8);

  EXPECT_EQ(int_set.size(), 8);
  EXPECT_EQ(int_set.capacity(), 11);
  EXPECT_EQ(int_set.elements()[7], 8);
}
TEST_F(IntSetTest, IntSetAdd2Test3) {
  int_set.Add(1);
  int_set.Add(2);
  int_set.Add(3);
  int_set.Add(4);
  int_set.Add(5);
  int_set.Add(5);

  EXPECT_EQ(int_set.size(), 5);
  EXPECT_EQ(int_set.capacity(), 7);
  EXPECT_EQ(int_set.elements()[0], 1);
}
