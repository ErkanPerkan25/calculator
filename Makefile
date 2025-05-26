CXX ?= g++

CXXFLAGS := -c -Wall -ansi -pedantic -std=c++20

all: calc

calc: calc.o Token.o
	$(CXX) -o calc calc.o Token.o


calc.o: calc.cpp 
	$(CXX) $(CXXFLAGS) calc.cpp

Token.o: Token.cpp Token.hpp
	$(CXX) $(CXXFLAGS) Token.cpp

clean:
	/bin/rm -f *~ *.o calc calc.o Token.o

.PHONY: clean
