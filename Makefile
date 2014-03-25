dda: *.h *.cc
	g++ -o dda *.h *.cc -std=c++11


clean: 
	rm dda
