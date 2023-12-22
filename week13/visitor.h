#ifndef _VISITOR_H_
#define _VISITOR_H_

#include <string>

// #include "int_node.h"
// #include "string_node.h"

// Visitor Pattern을 활용하여 순회 알고리즘을 Node 객체로 부터 분리하여 봅시다.
// • Circular dependency가 발생하는 경우, 적절한 forward declaration으로 해결

class IntNode;
class StringNode;

class Visitor {
 public:
  virtual void EnterIntNode(IntNode* node) = 0;
  virtual void ExitIntNode(IntNode* node) = 0;
  virtual void EnterStringNode(StringNode* node) = 0;
  virtual void ExitStringNode(StringNode* node) = 0;
  virtual std::string Result() = 0;
};

#endif  // _VISITOR_H_
