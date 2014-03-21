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

  int NodeNum() {
    return node_num_;
  }

  int NodeColor(int node_idx) {
    return node_color_[node_idx];
  }

  std::vector<int> Neighbor(int node_idx) {
    return adj_list_[node_idx];
  }


  int node_num_;
  double connectivity_;
  GraphType type_;
  std::vector<int> node_color_;
  std::vector< std::vector<int> > adj_list_;
};

#endif