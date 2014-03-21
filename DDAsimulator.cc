#include <vector>
#include "DDAsimulator.h"

void DDAsimulator::Init() {
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
void DDAsimulator::Run() {}
void DDAsimulator::PrintOutput() {}