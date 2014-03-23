#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>
#include "DDA.h"
#include "typedef.h"


class Node {
 public:
  Node(int idx, int color) {
    idx_ = idx;
    color_ = color;
    degree_ = 0;
  }
  ~Node() {}

  int degree() {
    return degree_;
  }

  void set_degree(int degree) {
    degree_ = degree;
  }

  std::vector<Node*> port() {
    return port_;
  }

  void add_port(Node* node) {
    port_.push_back(node);
  }
  
  int idx() {
    return idx_;
  } 

  int color() {
    return color_;
  }
  
  State state() {
    return state_;
  }

  void set_state(State state) {
    state_ = state;
  }
  
  MessageSet msg_send() {
    return msg_send_;
  }

  void set_msg_send(MessageSet msg_send) {
    msg_send_ = msg_send;
  }

  std::vector<int> Xset() {
    return Xset_;
  }

  void set_Xset(std::vector<int> Xset) {
    Xset_ = Xset;
  }

  std::vector<int> Mset() {
    return Mset_;
  }

  void set_Mset(std::vector<int> Mset) {
    Mset_ = Mset;
  }

  int matched_port() {
    return matched_port_;
  }

  void set_matched_port(int port) {
    matched_port_ = port;
  }

  void empty_msg_send() {
    std::fill(msg_send_.begin(), msg_send_.end(), Message(""));
  }


 private:
  int idx_;
  int color_;
  int degree_;
  int matched_port_;
  State state_;
  MessageSet msg_send_;
  std::vector<Node*> port_;
  std::vector<int> Xset_;
  std::vector<int> Mset_;
};


#endif