#include <iostream>
#include <vector>
#include "DDAsimulator.h"

void DDAsimulator::Init() {
  // build the port-numbered network according to the graph
  for (int i = 0; i < graph_->node_num(); ++i) {
    Node* new_node = new Node(i, graph_->node_color(i));
    node_.push_back(new_node);
  }

  std::vector<int> neighbor;
  for (int i = 0; i < graph_->node_num(); ++i) {
    neighbor = graph_->Neighbor(i);

    // set degree of the node
    node_[i]->set_degree(neighbor.size());    

    // set ports of the node
    for (int j = 0; j < neighbor.size(); ++j) {
      node_[i]->add_port(node_[neighbor[j]]);
    }  
  }
}

void DDAsimulator::PrintNetwork() {
  std::vector<Node*> port;
  for (int i = 0; i < graph_->node_num(); ++i) {
    std::cout << "node " << i << " ports: ";
    port = node_[i]->port();
    for (int j = 0; j < port.size(); ++j) {
      std::cout << j << "-" << port[j]->idx() << " ";
    }
    std::cout << std::endl;
  }
}

void DDAsimulator::Run() {
  for (int i = 0; i < node_.size(); ++i) {      
    dda_->InitNode(node_[i]);
  }

  for (int r = 1; r <= max_round_num_; ++r) {
    for (int i = 0; i < node_.size(); ++i) {      
      node_[i]->empty_msg_send();
    }
    

    for (int i = 0; i < node_.size(); ++i) {      
      dda_->Send(node_[i], r);
    }

    for (int i = 0; i < node_.size(); ++i) {
      dda_->Receive(node_[i], r);
    }

    int stop_node_num = 0;
    for (int i = 0; i < node_.size(); ++i) {
      stop_node_num += (int) dda_->Stop(node_[i]);
    }

    

    // std::cout << "round " << r << std::endl;
    // for (int i = 0; i < node_.size(); ++i) {    
    //   MessageSet msg_send = node_[i]->msg_send();
    //   std::cout << node_[i]->state() << " ";
    //   for (int j = 0; j < msg_send.size(); ++j) {
    //     if (!msg_send[j].empty()) {
    //       std::cout << j << " " << msg_send[j] << " ";
    //     }
    //   }
    //   std::cout << std::endl;
    // }

    std::cout << "round " << r << " stop node num: " << stop_node_num << std::endl;

    if (stop_node_num == node_.size()) {
      break;
    }
  }
}

void DDAsimulator::PrintOutput() {
  std::cout << "output" << std::endl;
  for (int i = 0; i < node_.size(); ++i) {      
    dda_->PrintOutput(node_[i]);
    // std::cout << node_[i]->state()  << std::endl;
  }  
}