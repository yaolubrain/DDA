#ifndef NODE_H
#define NODE_H

#include <vector>
#include "DDA.h"
#include "typedef.h"

class Node {
 public:
  Node(int idx, int color) {
    idx_ = idx;
    color_ = color;
    degree_ = 0;
    state_ = "";
    msg_send_ = "";
    msg_receive_ = "";
  }
  ~Node() {}

  void set_degree(int degree) {
    degree_ = degree;
  }

  void set_port(Node* node) {
    port_.push_back(node);
  }

  void set_dda(DDA* dda) {
    dda_ = dda;
  }

  void Init() {

  }

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