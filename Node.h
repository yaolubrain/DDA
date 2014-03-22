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

  void Init() {
    state_ = dda_->InitState(color_);
  }

  // void Send(int round_idx) {
  //   for (int i = 0; i < port_.size(); ++i) {
  //     Message msg = dda_->Send(state_, i, degree_, color_, round_idx);
  //     msg_send_.push_back(msg);
  //   }    
  // }


  // void Receive(int round_idx) {
  //   for (int i = 0; i < port_.size(); ++i) {
  //     Message msg = port_[i]->ReceiverMessage(idx_);
  //     msg_receive_.push_back(msg);
  //   }

  //   state_ = dda_->Receive(state_, msg_receive_, degree_, color_, round_idx);
  // }

  // Message ReceiverMessage(int receiver_idx) {
  //   for (int i = 0; i < port_.size(); ++i) {
  //     if (port_[i]->idx() == receiver_idx) {
  //       return msg_send_[i];
  //     }
  //   }

  //   std::cerr << "node " << idx_ << " has no receiver Node " << receiver_node_idx << std::endl;
  // }


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
  
  StateType state() {
    return state_;
  }

  void set_state(StateType state) {
    state_ = state;
  }
  
  MessageSet msg_send() {
    return msg_send_;
  }

  void set_msg_send(MessageSet msg_send) {
    msg_send_ = msg_send;
  }

  MessageSet msg_recevie() {
    return msg_receive_;
  }

  void set_msg_receive(MessageSet msg_receive) {
    msg_receive_ = msg_receive;
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

 private:
  int idx_;
  int color_;
  int degree_;
  int matched_port_;
  StateType state_;
  MessageSet msg_send_;
  MessageSet msg_receive_;
  std::vector<Node*> port_;
  std::vector<int> Xset_;
  std::vector<int> Mset_;
};


#endif