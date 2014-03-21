dda: main.cc DDAsimulator.h DDAsimulator.cc Node.h Graph.h DDA.h
	g++ -o dda main.cc DDAsimulator.h DDAsimulator.cc Node.h Graph.h DDA.h

clean: 
	rm dda
