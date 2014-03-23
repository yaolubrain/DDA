dda: main.cc DDAsimulator.h DDAsimulator.cc Node.h Graph.h Graph.cc DDA.h BMM.h BMM.cc
	g++ -o dda main.cc DDAsimulator.h DDAsimulator.cc Node.h Graph.h Graph.cc DDA.h BMM.h BMM.cc -std=c++11


clean: 
	rm dda
