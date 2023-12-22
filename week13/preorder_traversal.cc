#include "preorder_traversal.h"

void PreorderTraversal::EnterIntNode(IntNode *node) {
  result_ += "(Int " + node->value() + ") :: ";
  if (node->left() != nullptr) node->left()->Visit(this);
  if (node->right() != nullptr) node->right()->Visit(this);
}

void PreorderTraversal::ExitIntNode(IntNode *node) {
  result_ += "";
}

void PreorderTraversal::EnterStringNode(StringNode *node) {
  result_ += "(String " + node->value() + ") :: ";
  if (node->left() != nullptr) node->left()->Visit(this);
  if (node->right() != nullptr) node->right()->Visit(this);
}

void PreorderTraversal::ExitStringNode(StringNode *node) {
  result_ += "";
}

std::string PreorderTraversal::Result() {
  result_ = result_.substr(0, result_.size() - 4);
  return result_;
}
