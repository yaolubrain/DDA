#ifndef DDASIMULATOR_H
#define DDASIMULATOR_H

#include <iostream>
#include <vector>
#include "Node.h"
#include "Graph.h"
#include "DDA.h"
#include "typedef.h"

class Node;
class Graph;
class DDA;

class DDAsimulator {
 public:
  DDAsimulator(Graph* graph, DDA* dda) {
    graph_ = graph;
    dda_= dda;
    max_round_num_ = 20;
  }

  ~DDAsimulator() {}

  void Init();
  void Run();
  void PrintOutput();
  void PrintNetwork();

 private:
  std::vector<Node*> node_;
  int max_round_num_;
  Graph* graph_;
  DDA* dda_;
};

#endif