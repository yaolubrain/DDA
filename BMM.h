#ifndef BMM_H
#define BMM_H

#include <vector>
#include "DDA.h"
#include "Node.h"
#include "typedef.h"

class Node;

class BMM : public DDA {
 public:
  BMM() {}
  ~BMM() {}

  void InitNode(Node* node);
  void Send(Node* node, int round_idx);
  void Receive(Node* node, int round_idx);
  bool Stop(Node* node);
  void PrintOutput(Node* node);

};


#endif