#include <iostream>
#include "DDAsimulator.h"
#include "Node.h"
#include "Graph.h"
#include "DDA.h"
#include "BMM.h"


int main() {

  // GraphType graph_type = "random";
  GraphType graph_type = "bipartite";
  Graph* graph = new Graph(10, 0.5, graph_type);
  graph->Init();
  // graph->PrintGraph();

  DDA* dda = new BMM;
  DDAsimulator* dda_simulator = new DDAsimulator(graph, dda);


  dda_simulator->Init();
  // dda_simulator->PrintNetwork();
  dda_simulator->Run();
  dda_simulator->PrintOutput();

  return 0;
}