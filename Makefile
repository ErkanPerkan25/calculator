CXX ?= g++

CXXFLAGS := -c -Wall -ansi -pedantic -std=c++20

all: calc

calc: calc.o
	$(CXX) -o calc calc.o


calc.o: calc.cpp 
	$(CXX) $(CXXFLAGS) calc.cpp

clean:
	/bin/rm -f *~ *.o calc calc.o 

.PHONY: clean
