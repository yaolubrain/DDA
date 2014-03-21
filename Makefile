dda: main.cc DDAsimulator.h DDAsimulator.cc Node.h Graph.h Graph.cc DDA.h
	g++ -o dda main.cc DDAsimulator.h DDAsimulator.cc Node.h Graph.h Graph.cc DDA.h -std=c++11


clean: 
	rm dda
