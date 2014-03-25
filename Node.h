#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

class Node {
 public:
  typedef std::unordered_map<int, int> PortHash;
  Node() {}
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

  void add_port_hash(int node, int port) {
    port_hash_[node] = port;
  }

  int port_hash(int node) {
    return port_hash_[node];
  }

  virtual void Init() {}
  virtual void Send(int round_idx) {}
  virtual void Receive(int round_idx) {}
  virtual bool stop() {}
  virtual void PrintOutput() {}
  virtual void clear_msg_send() {}

 protected:
  int idx_;
  int color_;
  int degree_;
  int matched_port_;

  std::vector<Node*> port_;
  PortHash port_hash_;
};


#endif