SHELL := /bin/bash
CXX = g++
CXXFLAGS = -g -std=c++14 -Wall -Werror=return-type -Werror=uninitialized -Wno-sign-compare
RM = rm -rf

TESTS = test-seat test-room1 test-room2
CATCH = test/catch/catch.o

all: $(TESTS)

test-all: $(TESTS)

test-seat: test/catch/catch.o test/test-seat.o seat.o
	$(CXX) $(CXXFLAGS) -o $@ $^
	./$@ --success

test-room1: test/catch/catch.o test/test-room1.o room.o seat.o
	$(CXX) $(CXXFLAGS) -o $@ $^
	./$@ --success

test-room2: test/catch/catch.o test/test-room2.o room.o seat.o
	$(CXX) $(CXXFLAGS) -o $@ $^
	./$@ --success

test/catch/catch.o: test/catch/catch.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

test-mem: test-room2
	valgrind --leak-check=full --error-exitcode=1 ./test-room2

clean:
	$(RM) *.o *.gc* test/*.o *.dSYM main $(TESTS) $(CATCH)

.PHONY: all test-all test-seat test-room1 test-room2 clean test-mem
