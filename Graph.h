#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include "typedef.h"

class Graph {
 public:
  Graph() {}
  ~Graph() {}
  
  void Init();

  GraphType type_;
  std::vector<int> node_color_;
  std::vector< std::vector<int> > adj_list_;
};

#endif