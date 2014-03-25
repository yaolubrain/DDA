#include <iostream>
#include "DDAsimulator.h"
#include "Node.h"
#include "Graph.h"
#include "DDA.h"
#include "BMM.h"


int main() {

  // GraphType graph_type = "random";
  std::string graph_type = "bipartite";
  Graph* graph = new Graph(100, 0.2, graph_type);
  graph->Init();
  // graph->PrintGraph();

  DDAType dda_type = "BMM"; 
  DDAsimulator* dda_simulator = new DDAsimulator(graph, dda_type);


  dda_simulator->Init();
  // dda_simulator->PrintNetwork();
  dda_simulator->Run();
  dda_simulator->PrintOutput();

  return 0;
}