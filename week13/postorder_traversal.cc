#include "postorder_traversal.h"

#include <string>

void PostorderTraversal::EnterIntNode(IntNode* node) {
  if (node->left() != nullptr) node->left()->Visit(this);
  if (node->right() != nullptr) node->right()->Visit(this);
  result_ += "(Int " + node->value() + ") :: ";
}

void PostorderTraversal::ExitIntNode(IntNode* node) {
  result_ += "";
}

void PostorderTraversal::EnterStringNode(StringNode* node) {
  if (node->left() != nullptr) node->left()->Visit(this);
  if (node->right() != nullptr) node->right()->Visit(this);
  result_ += "(String " + node->value() + ") :: ";
}

void PostorderTraversal::ExitStringNode(StringNode* node) {
  result_ += "";
}

std::string PostorderTraversal::Result() {
  result_ = result_.substr(0, result_.size() - 4);
  return result_;
}
