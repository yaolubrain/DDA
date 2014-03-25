#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>

class Graph {
 public:
  Graph(int node_num, double connectivity, std::string type) {
    node_num_ = node_num;
    type_ = type;
    connectivity_ = connectivity;
  }
  ~Graph() {}
  
  void Init();
  void PrintGraph();

  int node_num() {
    return node_num_;
  }

  int node_color(int node_idx) {
    return node_color_[node_idx];
  }

  std::vector<int> Neighbor(int node_idx) {
    return adj_list_[node_idx];
  }

 private:
  int node_num_;
  double connectivity_;
  std::string type_;
  std::vector<int> node_color_;
  std::vector< std::vector<int> > adj_list_;
};

#endif