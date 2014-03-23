<<<<<<< HEAD
=======
#include <iostream>
>>>>>>> 5adc2e49d7a5f6c870ba3b1a57edd59e50c40219
#include <vector>
#include "DDAsimulator.h"

void DDAsimulator::Init() {
  // build the port-numbered network according to the graph
<<<<<<< HEAD
  for (int i = 0; i < graph_->NodeNum(); ++i) {
    Node* new_node = new Node(i, graph_->NodeColor(i));
    node_.push_back(new_node);
  }

  for (int i = 0; i < graph_->NodeNum(); ++i) {
    std::vector<int> neighbor = graph_->Neighbor(i);
=======
  for (int i = 0; i < graph_->node_num(); ++i) {
    Node* new_node = new Node(i, graph_->node_color(i));
    node_.push_back(new_node);
  }

  std::vector<int> neighbor;
  for (int i = 0; i < graph_->node_num(); ++i) {
    neighbor = graph_->Neighbor(i);
>>>>>>> 5adc2e49d7a5f6c870ba3b1a57edd59e50c40219

    // set degree of the node
    node_[i]->set_degree(neighbor.size());    

    // set ports of the node
    for (int j = 0; j < neighbor.size(); ++j) {
<<<<<<< HEAD
      node_[i]->set_port(node_[neighbor[j]]);
    }

    node_[i]->set_dda(dda_);

    // set initial state and message
    node_[i]->Init();
=======
      node_[i]->add_port(node_[neighbor[j]]);
    }  
>>>>>>> 5adc2e49d7a5f6c870ba3b1a57edd59e50c40219
  }
}

void DDAsimulator::PrintNetwork() {
<<<<<<< HEAD
  for (int i = 0; i < graph_->NodeNum(); ++i) {
    std::cout << "node " << i << " ports: ";
    std::vector<Node*> port = node_[i]->port();
    for (int j = 0; j < port.size(); ++j) {
      std::cout << j << "-" << port[j]->node_idx() << " ";
=======
  std::vector<Node*> port;
  for (int i = 0; i < graph_->node_num(); ++i) {
    std::cout << "node " << i << " ports: ";
    port = node_[i]->port();
    for (int j = 0; j < port.size(); ++j) {
      std::cout << j << "-" << port[j]->idx() << " ";
>>>>>>> 5adc2e49d7a5f6c870ba3b1a57edd59e50c40219
    }
    std::cout << std::endl;
  }
}

void DDAsimulator::Run() {
<<<<<<< HEAD
  for (int r = 1; r <= max_round_num_; ++r) {
    for (int i = 0; i < node_.size(); ++i) {
      node_[i]->Send(r);
    }

    for (int i = 0; i < node_.size(); ++i) {
      node_[i]->Receive(r);
=======
  for (int i = 0; i < node_.size(); ++i) {      
    dda_->InitNode(node_[i]);
  }

  for (int r = 1; r <= max_round_num_; ++r) {
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

    if (stop_node_num == node_.size()) {
      break;
>>>>>>> 5adc2e49d7a5f6c870ba3b1a57edd59e50c40219
    }

    std::cout << "communication round " << r << std::endl;
  }
}

<<<<<<< HEAD
void DDAsimulator::PrintOutput() {}
=======
void DDAsimulator::PrintOutput() {
  std::cout << "output" << std::endl;
  for (int i = 0; i < node_.size(); ++i) {      
    dda->PrintOutput(node_[i]);
    std::cout << std::endl;
<<<<<<< HEAD
  }
  
}
>>>>>>> 5adc2e49d7a5f6c870ba3b1a57edd59e50c40219
=======
  }  
}
>>>>>>> f18ec32917dd343fc96d21612cf944d32fde82ed
