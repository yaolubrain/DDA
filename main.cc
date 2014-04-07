#include <iostream>
#include "DDAsimulator.h"
#include "Graph.h"


int main() {

  std::string graph_type = "random";
  // std::string graph_type = "bipartite";
  Graph* graph = new Graph(100, 0.5, graph_type);
  graph->Init();
  // graph->PrintGraph();

  // DDAType dda_type = "BMM"; 
  // std::string dda_type = "VC3"; 
  std::string dda_type = "VC2"; 
  DDAsimulator* dda_simulator = new DDAsimulator(graph, dda_type);


  dda_simulator->Init();
  // dda_simulator->PrintNetwork();
  dda_simulator->Run();
  dda_simulator->PrintOutput();

  return 0;
}