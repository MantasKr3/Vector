CXX=c++
CXXFLAGS=-g -std=c++11 

main: F.o studentas.o 
	g++ -std=c++11 -o main main.cpp F.o studentas.o
F:
	g++ -std=c++11 -c F.cpp
studentas:
	g++ -std=c++11 -c studentas.cpp
clean:
	rm *.o main
