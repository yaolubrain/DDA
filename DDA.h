#ifndef DDA_H
#define DDA_H 

#include "Node.h"
#include "typedef.h"

class Node;

class DDA {
 public:
  DDA() {}
  ~DDA() {}
  
  virtual void InitNode(Node* node) {}
  virtual void Send(Node* node, int round_idx) {}
  virtual void Receive(Node* node, int round_idx) {}  
};


#endif