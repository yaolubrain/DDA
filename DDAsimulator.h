#ifndef DDASIMULATOR_H
#define DDASIMULATOR_H

#include <iostream>
#include <vector>
#include "Node.h"
#include "Graph.h"

class Node;
class Graph;
class DDA;

class DDAsimulator {
 public:
  DDAsimulator(Graph* graph, std::string& dda_type) {
    graph_ = graph;
    dda_type_ = dda_type;
    if (dda_type_ == "BMM") {
      max_round_num_ = 2*graph_->node_num(); 
    } else if (dda_type_ == "VC3") {
      max_round_num_ = graph_->node_num(); 
    }
  }

  ~DDAsimulator() {}

  void Init();
  void Run();
  void PrintOutput();
  void PrintNetwork();

 private:
  std::vector<Node*> nodes_;
  int max_round_num_;
  Graph* graph_;
  std::string dda_type_; 
};

#endif