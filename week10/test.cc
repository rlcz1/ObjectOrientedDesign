#include "gtest/gtest.h"
#include "stack.h"
#include "queue.h"
#include "vector.h"
#include "list.h"

class ListIntTest : public ::testing::Test {
 protected:
  List<int> list_;
  void SetUp() override {}
  void TearDown() override {}
 public :
  ListIntTest() : list_() {}
};

TEST_F(ListIntTest, PushBack) {
  list_.PushBack(4);
  EXPECT_EQ(list_.size(), 1);
}

TEST_F(ListIntTest, PushBack2) {
  list_.PushBack(4);
  list_.PushBack(5);
  list_.PushBack(6);
  list_.PushBack(7);
  EXPECT_EQ(list_.size(), 4);
}

TEST_F(ListIntTest, AssertTest) {
  list_.PushBack(4);
  list_.PushBack(5);
  list_.PopBack();
  list_.PopBack();
  ASSERT_DEATH(list_.PopFront(), "Out-of-bound");
}

TEST_F(ListIntTest, PopAssertTest) {
  ASSERT_DEATH(list_.PopBack(), "Out-of-bound");
}

class StackIntTest : public ::testing::Test {
 protected:
  Stack<int> stack_;
  void SetUp() override {}
  void TearDown() override {}
 public :
  StackIntTest() : stack_(3) {}
};

TEST_F(StackIntTest, Push) {
  stack_.Push(4);
  stack_.Push(5);
  stack_.Push(6);
  stack_.Push(7);
  EXPECT_EQ(stack_.capacity(), 7);
}

TEST_F(StackIntTest, Pop) {
  stack_.Push(4);
  stack_.Push(5);
  EXPECT_EQ(stack_.Pop(), 5);
}

class StackFloatTest : public ::testing::Test {
 protected:
  Stack<float> stack_;
  void SetUp() override {}
  void TearDown() override {}
 public :
  StackFloatTest() : stack_(3) {}
};

TEST_F(StackFloatTest, Push) {
  stack_.Push(4.0);
  EXPECT_EQ(stack_.capacity(), 3);
}

TEST_F(StackFloatTest, Push2) {
  stack_.Push(4.1);
  stack_.Push(5.2);
  stack_.Push(6.3);
  stack_.Push(7.4);
  EXPECT_EQ(stack_.capacity(), 7);
}

class StackStringTest : public ::testing::Test {
 protected:
  Stack<std::string> stack_;
  void SetUp() override {}
  void TearDown() override {}
 public :
  StackStringTest() : stack_(3) {}
};

TEST_F(StackStringTest, Pop) {
  stack_.Push("1");
  stack_.Push("2");
  stack_.Push("3");
  EXPECT_EQ(stack_.Pop(), "3");
}

// Queue
class QueueIntTest : public ::testing::Test {
 protected:
  Queue<int> queue_;
  void SetUp() override {}
  void TearDown() override {}
 public :
  QueueIntTest() : queue_() {}
};

TEST_F(QueueIntTest, Add) {
  queue_.Add(4);
  EXPECT_EQ(queue_.size(), 1);
}

TEST_F(QueueIntTest, Add2) {
  queue_.Add(4);
  queue_.Add(5);
  queue_.Add(6);
  queue_.Add(7);
  EXPECT_EQ(queue_.size(), 4);
}

TEST_F(QueueIntTest, Poll) {
  queue_.Add(1);
  queue_.Add(2);
  queue_.Add(3);
  EXPECT_EQ(queue_.Poll(), 1);
}

class QueueStringTest : public ::testing::Test {
 protected:
  Queue<std::string> queue_;
  void SetUp() override {}
  void TearDown() override {}
 public :
  QueueStringTest() : queue_() {}
};

TEST_F(QueueStringTest, Poll) {
  queue_.Add("1");
  queue_.Add("2");
  queue_.Add("3");
  EXPECT_EQ(queue_.Poll(), "1");
}

TEST_F(QueueStringTest, PollAssert) {
  queue_.Add("1");
  queue_.Poll();
  ASSERT_DEATH(queue_.Poll(), "Out-of-bound");
}
