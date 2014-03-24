#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
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
  
  Message msg_send(int port) {
    return msg_send_[port];
  }

  void set_msg_send(Message msg_send, int port) {
    msg_send_[port] = msg_send;
  }


  int matched_port() {
    return matched_port_;
  }

  void set_matched_port(int port) {
    matched_port_ = port;
  }

  void clear_msg_send() {
    msg_send_.assign(degree_, Message(""));
  }

  void add_port_hash(int node, int port) {
    port_hash_[node] = port;
  }

  int port_hash(int node) {
    return port_hash_[node];
  }

  void insert_Xset(int port) {
    Xset_.insert(port);
  }

  void erase_Xset(int port) {
    Xset_.erase(port);
  }

  void insert_Mset(int port) {
    Mset_.insert(port);
  }

  int min_Mset() {
    return *Mset_.begin();
  }

  void msg_send_all_matched() {
    msg_send_.assign(degree_, Message("matched"));
  }

  bool empty_Mset() {
    return Mset_.empty();
  }

  bool empty_Xset() {
    return Xset_.empty();
  }
  
 private:
  int idx_;
  int color_;
  int degree_;
  int matched_port_;
  State state_;
  MessageSet msg_send_;
  std::vector<Node*> port_;
  PortHash port_hash_;
  std::set<int> Xset_;
  std::set<int> Mset_;
};


#endif