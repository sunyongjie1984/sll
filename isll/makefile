isll: islln.o isll.o
	g++ isll.o islln.o main.cpp -std=c++0x -g -Wall -o isll
islln.o: islln.h
	g++ -std=c++0x -c islln.cpp
isll.o: isll.h islln.h
	g++ -std=c++0x -c isll.cpp
clean:
	rm -rf *.gch isll *.o