#include <iostream>
#include "DDAsimulator.h"
#include "Node.h"
#include "Graph.h"
#include "DDA.h"


int main() {

  Graph* graph = new Graph;
  DDA* dda = new DDA;
  DDAsimulator* dda_simulator = new DDAsimulator(graph, dda);

  dda_simulator->Init();
  dda_simulator->Run();
  dda_simulator->PrintOutput();
  
  return 0;
}