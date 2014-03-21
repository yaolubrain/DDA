#include <iostream>

class DDAsimulator {
 public:
  DDAsimulator(int node_num, double connectivity_) {}
  ~DDAsimulator() {}

  Init();
  Run();
  PrintOutput();
  
  int node_num_;
  double connectivity_;

  vector< vector<Node*> > graph_;
};