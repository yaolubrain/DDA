#ifndef NODE_H
#define NODE_H

#include <vector>
#include "DDA.h"
#include "typedef.h"

class Node {
 public:
  Node() {}
  ~Node() {}
  
  void Send();
  void Message();
  void Receive();

  int idx_;
  int color_;
  int degree_;
  StateType state_;
  MessageType msg_send_;
  MessageType msg_receive_;
  std::vector<Node*> port_;
  DDA* dda_;
};


#endif