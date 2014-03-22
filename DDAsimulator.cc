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
    dda->InitNode(node_[i]);
  }

  for (int r = 1; r <= max_round_num_; ++r) {
    for (int i = 0; i < node_.size(); ++i) {      
      dda_->Send(node_[i], r);
    }

    for (int i = 0; i < node_.size(); ++i) {
      dda_->Receive(node_[i], r);
    }

    std::cout << "communication round " << r << std::endl;
  }
}

void DDAsimulator::PrintOutput() {}