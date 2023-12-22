#include "gtest/gtest.h"

#include "preorder_traversal.h"
#include "postorder_traversal.h"
#include "int_node.h"
#include "string_node.h"
#include "visitor.h"
#include "node.h"

class PostorderTraversalTest : public ::testing::Test {
 public:
  PostorderTraversalTest() : postorder_traversal() {}
 protected:
  void SetUp() override {}
  void TearDown() override {}
  PostorderTraversal* postorder_traversal;
};

TEST_F(PostorderTraversalTest, PostorderTraversalTest1) {
  postorder_traversal = new PostorderTraversal();
  Node* root = new IntNode(3,
    new StringNode(std::string("hi"), nullptr, nullptr),
    new IntNode(-42,
      new IntNode(0, nullptr, nullptr),
      new StringNode(std::string("bye"), nullptr, nullptr)));
  root->Visit(postorder_traversal);
  EXPECT_EQ(
    postorder_traversal->Result(),
    "(String hi) :: (Int 0) :: (String bye) :: (Int -42) :: (Int 3)");
}

TEST_F(PostorderTraversalTest, PostorderTraversalTest2) {
  postorder_traversal = new PostorderTraversal();
  Node* root = new IntNode(
    1,
    new IntNode(
      2,
      new IntNode(3, nullptr, nullptr),
      nullptr),
    new IntNode(
      4,
      nullptr,
      new StringNode(std::string("hi"), nullptr, nullptr)));
  root->Visit(postorder_traversal);
  EXPECT_EQ(
    postorder_traversal->Result(),
    "(Int 3) :: (Int 2) :: (String hi) :: (Int 4) :: (Int 1)");
}

TEST_F(PostorderTraversalTest, PostorderTraversalTest3) {
  postorder_traversal = new PostorderTraversal();
  Node* root = new StringNode(
    std::string("hi"),
    new StringNode(std::string("bye"), nullptr, nullptr),
    nullptr);
  root->Visit(postorder_traversal);
  EXPECT_EQ(
    postorder_traversal->Result(),
    "(String bye) :: (String hi)");
}

TEST_F(PostorderTraversalTest, PostorderTraversalTest4) {
  postorder_traversal = new PostorderTraversal();
  Node* root = new StringNode(
    std::string("hi"),
    new StringNode(std::string("bye"), nullptr, nullptr),
    new IntNode(3, nullptr, nullptr));
  root->Visit(postorder_traversal);
  EXPECT_EQ(
    postorder_traversal->Result(),
    "(String bye) :: (Int 3) :: (String hi)");
}

TEST_F(PostorderTraversalTest, PostorderTraversalTest5) {
  postorder_traversal = new PostorderTraversal();
  Node* root = new StringNode(
    std::string("hi"),
    new StringNode(std::string("bye"), nullptr, nullptr),
    new IntNode(3,
      new StringNode(std::string("byee"), nullptr, nullptr),
      nullptr));
  root->Visit(postorder_traversal);
  EXPECT_EQ(
    postorder_traversal->Result(),
    "(String bye) :: (String byee) :: (Int 3) :: (String hi)");
}

class PreorderTraversalTest : public ::testing::Test {
 public:
  PreorderTraversalTest() : preorder_traversal() {}
 protected:
  void SetUp() override {}
  void TearDown() override {}
  PreorderTraversal* preorder_traversal;
};

TEST_F(PreorderTraversalTest, PreorderTraversalTest1) {
  preorder_traversal = new PreorderTraversal();
  Node* root = new IntNode(3,
    new StringNode(std::string("hi"), nullptr, nullptr),
    new IntNode(-42,
      new IntNode(0, nullptr, nullptr),
      new StringNode(std::string("bye"), nullptr, nullptr)));
  root->Visit(preorder_traversal);
  EXPECT_EQ(
    preorder_traversal->Result(),
    "(Int 3) :: (String hi) :: (Int -42) :: (Int 0) :: (String bye)");
}

TEST_F(PreorderTraversalTest, PreorderTraversalTest2) {
  preorder_traversal = new PreorderTraversal();
  Node* root = new IntNode(
    1,
    new IntNode(
      2,
      new IntNode(3, nullptr, nullptr),
      nullptr),
    new IntNode(
      4,
      nullptr,
      new StringNode(std::string("hi"), nullptr, nullptr)));
  root->Visit(preorder_traversal);
  EXPECT_EQ(
    preorder_traversal->Result(),
    "(Int 1) :: (Int 2) :: (Int 3) :: (Int 4) :: (String hi)");
}

TEST_F(PreorderTraversalTest, PreorderTraversalTest3) {
  preorder_traversal = new PreorderTraversal();
  Node* root = new StringNode(
      std::string("hi"),
      new StringNode(std::string("bye"), nullptr, nullptr),
      nullptr);
  root->Visit(preorder_traversal);
  EXPECT_EQ(
    preorder_traversal->Result(),
    "(String hi) :: (String bye)");
}

TEST_F(PreorderTraversalTest, PreorderTraversalTest4) {
  preorder_traversal = new PreorderTraversal();
  Node* root = new StringNode(
    std::string("hi"),
    new StringNode(std::string("bye"), nullptr, nullptr),
    new IntNode(3, nullptr, nullptr));
  root->Visit(preorder_traversal);
  EXPECT_EQ(
    preorder_traversal->Result(),
    "(String hi) :: (String bye) :: (Int 3)");
}

TEST_F(PreorderTraversalTest, PreorderTraversalTest5) {
  preorder_traversal = new PreorderTraversal();
  Node* root = new StringNode(
    std::string("hi"),
    new StringNode(std::string("bye"), nullptr, nullptr),
    new IntNode(3,
      new StringNode(std::string("byee"), nullptr, nullptr),
      nullptr));
  root->Visit(preorder_traversal);
  EXPECT_EQ(
    preorder_traversal->Result(),
    "(String hi) :: (String bye) :: (Int 3) :: (String byee)");
}
