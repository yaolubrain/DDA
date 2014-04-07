#include <iostream>
#include <vector>
#include "DDAsimulator.h"
#include "BMM.h"
#include "VC3.h"
#include "VC2.h"

void DDAsimulator::Init() {
  // build the port-numbered network according to the graph
  for (int i = 0; i < graph_->node_num(); ++i) {
    Node* new_node;

    if (dda_type_ == "BMM") {
      new_node = new BMM(i, graph_->node_color(i));      
    } else if (dda_type_ == "VC3") {
      new_node = new VC3(i, graph_->node_color(i));      
    } else if (dda_type_ == "VC2") {
      new_node = new VC2(i, graph_->node_color(i));      
    }

    nodes_.push_back(new_node);
  }

  std::vector<int> neighbor;
  for (int i = 0; i < graph_->node_num(); ++i) {
    neighbor = graph_->Neighbor(i);

    // set degree of the node
    nodes_[i]->set_degree(neighbor.size());    

    // set ports of the node
    for (int j = 0; j < neighbor.size(); ++j) {
      nodes_[i]->add_port(nodes_[neighbor[j]]);
      nodes_[i]->add_port_hash(neighbor[j], j);
    }  
  }

}

void DDAsimulator::PrintNetwork() {
  std::vector<Node*> port;
  for (int i = 0; i < graph_->node_num(); ++i) {
    std::cout << "node " << i << " ports: ";
    port = nodes_[i]->port();
    for (int j = 0; j < port.size(); ++j) {
      std::cout << j << "-" << port[j]->idx() << " ";
    }
    std::cout << std::endl;
  }
}

void DDAsimulator::RunInteral() {
  for (int r = 1; r <= max_round_num_; ++r) {
    for (int i = 0; i < nodes_.size(); ++i) {      
      nodes_[i]->ClearMsgSend();
    }          

    for (int i = 0; i < nodes_.size(); ++i) {      
      nodes_[i]->Send(r);
    }  

    for (int i = 0; i < nodes_.size(); ++i) {
      nodes_[i]->Receive(r);
    }  

    int stop_node_num = 0;
    for (int i = 0; i < nodes_.size(); ++i) {
      stop_node_num += (int) nodes_[i]->IsStopped();      
    }  

    std::cout << "round " << r << " stop node num: " << stop_node_num << std::endl;  

    if (stop_node_num == nodes_.size()) {
      break;
    }
  }
}

void DDAsimulator::Run() {
  for (int i = 0; i < nodes_.size(); ++i) {      
    nodes_[i]->Init();
  }

  if (dda_type_ != "VC2") {    

    RunInteral();

  } else {    

    while (!AllEdgeSaturated()) {

      for (int i = 0; i < nodes_.size(); ++i) {      
        if (nodes_[i]->IsSaturated())        
          nodes_[i]->Init();
        }
      }

      RunInteral();
      DeleteSaturatedEdges();      
    }  

  }
}

bool DDAsimulator::AllEdgeSaturated() {
  bool saturated = true;
  for (int i = 0; i < nodes_.size(); ++i) {
    if (!nodes_[i]->IsSaturated()) {
      saturated = false;
      break;
    }      
  }

  return saturated;
}

void DDAsimulator::DeleteSaturatedEdges() {
  for (int i = 0; i < nodes_.size(); ++i) {
    if (nodes_[i]->IsSaturated()) {
      std::vector<Node*> port = nodes_[i]->port();
      for (int j = 0; j < port.size(); ++j) {      
        port[j]->delete_port(port[j]->port_hash(nodes_[j]->idx()));
        nodes_[i]->delete_port(j);  
      }
    }
  }
}


void DDAsimulator::PrintOutput() {
  std::cout << "output" << std::endl;
  for (int i = 0; i < nodes_.size(); ++i) {      
    nodes_[i]->PrintOutput();
  }  
}