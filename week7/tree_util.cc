#include "node.h"
#include "int_node.h"
#include "string_node.h"
#include "tree_util.h"

TreeUtil* TreeUtil::instance_ = nullptr;

TreeUtil::TreeUtil() {}

TreeUtil* TreeUtil::GetInstance() {
  if (!instance_) {
    instance_ = new TreeUtil();
  }
  return instance_;
}

const std::string TreeUtil::PreOrderTraversal(const Node *node) const {
  if (node == nullptr) return "";

  std::string str = "";

  if (node != nullptr) str += (node)->value();
  if (node->left() != nullptr) str += "," + PreOrderTraversal(node->left());
  if (node->right() != nullptr) str += "," + PreOrderTraversal(node->right());

  return str;
}

const std::string TreeUtil::InOrderTraversal(const Node *node) const {
  if (node == nullptr) return "";

  std::string str = "";

  str += InOrderTraversal(node->left());
  if (node->left() != nullptr) str += ",";

  if (node != nullptr) str += (node)->value();

  if (node->right() != nullptr) str += ",";
  str += InOrderTraversal(node->right());

  return str;
}

const std::string TreeUtil::PostOrderTraversal(const Node *node) const {
  if (node == nullptr) return "";

  std::string str = "";

  str += PostOrderTraversal(node->left());
  if (node->left() != nullptr) str += ",";

  str += PostOrderTraversal(node->right());
  if (node->right() != nullptr) str += ",";

  if (node != nullptr) str += (node)->value();

  return str;
}
