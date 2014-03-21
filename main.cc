#include <iostream>
#include "DDAsimulator.h"
#include "Node.h"
#include "Graph.h"
#include "DDA.h"


int main() {

  GraphType graph_type = "random";
  Graph* graph = new Graph(10, 0.1, graph_type);
  graph->Init();
  // graph->PrintGraph();

  DDA* dda = new DDA;
  DDAsimulator* dda_simulator = new DDAsimulator(graph, dda);

  dda_simulator->Init();
  dda_simulator->Run();
  dda_simulator->PrintOutput();

  return 0;
}