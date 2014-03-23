#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include "typedef.h"

class Graph {
 public:
  Graph(int node_num, double connectivity, GraphType type) {
    node_num_ = node_num;
    type_ = type;
    connectivity_ = connectivity;
  }
  ~Graph() {}
  
  void Init();
  void PrintGraph();

<<<<<<< HEAD
  int NodeNum() {
    return node_num_;
  }

  int NodeColor(int node_idx) {
=======
  int node_num() {
    return node_num_;
  }

  int node_color(int node_idx) {
>>>>>>> 5adc2e49d7a5f6c870ba3b1a57edd59e50c40219
    return node_color_[node_idx];
  }

  std::vector<int> Neighbor(int node_idx) {
    return adj_list_[node_idx];
  }

 private:
  int node_num_;
  double connectivity_;
  GraphType type_;
  std::vector<int> node_color_;
  std::vector< std::vector<int> > adj_list_;
};

#endif