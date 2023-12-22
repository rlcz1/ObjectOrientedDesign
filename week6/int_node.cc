#include "node.h"
#include "int_node.h"

// IntNode::IntNode(int value, const Node * left, const Node * right)
// : Node(left, right), value_(value) {}

IntNode::IntNode(int value, Node* left, Node* right)
: Node(left, right), value_(value) {}

const int IntNode::value() const {
  return value_;
}
