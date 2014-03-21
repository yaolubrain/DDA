#include <vector>
#include "DDAsimulator.h"

void DDAsimulator::Init() {
  // build the port-numbered network according to the graph
  for (int i = 0; i < graph_->NodeNum(); ++i) {
    Node* new_node = new Node(i, graph_->NodeColor(i));
    node_.push_back(new_node);
  }

  for (int i = 0; i < graph_->NodeNum(); ++i) {
    std::vector<int> neighbor = graph_->Neighbor(i);

    // set degree of the node
    node_[i]->set_degree(neighbor.size());    

    // set ports of the node
    for (int j = 0; j < neighbor.size(); ++j) {
      node_[i]->set_port(node_[neighbor[j]]);
    }

    node_[i]->set_dda(dda_);

    // set initial state and message
    node_[i]->Init();
  }
}

void DDAsimulator::PrintNetwork() {
  for (int i = 0; i < graph_->NodeNum(); ++i) {
    std::cout << "Node " << i << " Ports: ";
    std::vector<Node*> port = node_[i]->port();
    for (int j = 0; j < port.size(); ++j) {
      std::cout << j << "-" << port[j]->node_idx() << " ";
    }
    std::cout << std::endl;
  }
}

void DDAsimulator::Run() {
  for (int r = 0; r < max_round_num_; ++r) {
    for (int i = 0; i < node_.size(); ++i) {
      node_[i]->Send(r);
    }

    for (int i = 0; i < node_.size(); ++i) {
      node_[i]->Receive(r);
    }

    std::cout << "Communication round " << r << std::endl;
  }
}

void DDAsimulator::PrintOutput() {}