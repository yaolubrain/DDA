dda: *.h *.cc
	g++ -o dda *.h *.cc -std=c++0x


clean: 
	rm dda
