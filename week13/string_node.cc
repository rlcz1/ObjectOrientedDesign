#include "string_node.h"
#include "visitor.h"
#include "int_node.h"
#include "postorder_traversal.h"
#include "preorder_traversal.h"

StringNode::StringNode(std::string value, Node *left, Node *right)
: Node(left, right), value_(value) {}

// visit
// visitor->Enter
// left->visit(visitor)
// right->visit(visitor)
// visitot->Exit

void StringNode::Visit(Visitor *visitor) {
  visitor->EnterStringNode(this);
  visitor->ExitStringNode(this);
}

std::string StringNode::value() {
  return value_;
}
