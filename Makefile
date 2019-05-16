CPPFLAGS= --std=c++14 -I ~/Software/FESolver/Eigen/
CXXFLAGS= -Wall

all: solver.o test.o
	c++ $(CXXFLAGS) -o solver solver.o test.o

solver.o: solver.cpp test.h
	c++ $(CPPFLAGS)	-c solver.cpp

test.o: test.cpp test.h
	c++ $(CPPFLAGS) -c test.cpp

clean: 
	rm -f test.o solver.o solver
