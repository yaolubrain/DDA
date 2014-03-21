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

  void Send(int round_idx) {
    for (int i = 0; i < port_.size(); ++i) {
      MessageType msg = dda_->Send(state_, i, degree_, color_, round_idx);
      msg_send_.push_back(msg);
    }    
  }


  void Receive(int round_idx) {
    for (int i = 0; i < port_.size(); ++i) {
      MessageType msg = port_[i]->ReceiverMessage(idx_);
      msg_receive_.push_back(msg);
    }

    state_ = dda_->Receive(state_, msg_receive_, degree_, color_, round_idx);
  }

  MessageType ReceiverMessage(int receiver_node_idx) {
    for (int i = 0; i < port_.size(); ++i) {
      if (port_[i]->node_idx() == receiver_node_idx) {
        return msg_send_[i];
      }
    }

    std::cerr << "Node " << idx_ << " has no receiver Node " << receiver_node_idx << std::endl;
  }


  void set_degree(int degree) {
    degree_ = degree;
  }

  void set_port(Node* node) {
    port_.push_back(node);
  }

  void set_dda(DDA* dda) {
    dda_ = dda;
  }

  std::vector<Node*> port() {
    return port_;
  }

  int node_idx() {
    return idx_;
  }

  

 private:
  int idx_;
  int color_;
  int degree_;
  StateType state_;
  std::vector<MessageType> msg_send_;
  std::vector<MessageType> msg_receive_;
  std::vector<Node*> port_;
  DDA* dda_;
};


#endif