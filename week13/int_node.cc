#include <iostream>

#include "int_node.h"
#include "visitor.h"
#include "postorder_traversal.h"
#include "preorder_traversal.h"


IntNode::IntNode(int value, Node* left, Node* right)
: Node(left, right), value_(value) {}

void IntNode::Visit(Visitor *visitor) {
  visitor->EnterIntNode(this);
  visitor->ExitIntNode(this);
}

std::string IntNode::value() {
  return std::to_string(value_);
}
