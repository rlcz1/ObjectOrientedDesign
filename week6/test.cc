#include "gtest/gtest.h"
#include "node.h"
#include "int_node.h"
#include "string_node.h"
#include "tree_util.h"

class TreeUtilTest : public ::testing::Test {
 public :
  TreeUtilTest() : tree_util() {}
 protected:
  void SetUp() override {}
  void TearDown() override {}
  TreeUtil* tree_util;
};

TEST_F(TreeUtilTest, TreeUtilTest1) {
  tree_util = TreeUtil::GetInstance();
  IntNode* root = new IntNode(1,
    new IntNode(2, nullptr, nullptr), new IntNode(3, nullptr, nullptr));
  EXPECT_EQ(tree_util->PreOrderTraversal(root), "1, 2, 3");
  delete root;
}

TEST_F(TreeUtilTest, TreeUtilTest2) {
  tree_util = TreeUtil::GetInstance();
  StringNode* root = new StringNode("A",
    new StringNode("B",
      new StringNode("D", nullptr, nullptr),
      new StringNode("E",
        new StringNode("F", nullptr, nullptr),
        new StringNode("G", nullptr, nullptr))),
    new StringNode("C", nullptr, nullptr));

  EXPECT_EQ(tree_util->InOrderTraversal(root), "D, B, F, E, G, A, C");
  delete root;
}

TEST_F(TreeUtilTest, TreeUtilTest3) {
  tree_util = TreeUtil::GetInstance();
  StringNode* root = new StringNode("A",
    new StringNode("B",
      new StringNode("D", nullptr, nullptr),
      new StringNode("E",
        new StringNode("F", nullptr, nullptr),
        new StringNode("G", nullptr, nullptr))),
    new StringNode("C", nullptr, nullptr));
  EXPECT_EQ(tree_util->PostOrderTraversal(root), "D, F, G, E, B, C, A");
  delete root;
}
