CXX = g++
CXXFLAGS = -g -std=c++14 -Wall -Wall -Werror=return-type  \
			-Werror=uninitialized -Wno-sign-compare
RM = rm -rf
TESTS = test-seat test-room1 test-room2

test-all: $(TESTS)

test-seat: test/catch/catch.o test/test-seat.o seat.o
test-room1: test/catch/catch.o test/test-room1.o room.o seat.o
test-room2: test/catch/catch.o test/test-room2.o room.o seat.o

$(TESTS):
	$(CXX) $(CXXFLAGS) -o $@ $^
	./$@ --success

clean:
	$(RM) *.o *.gc* test/*.o main $(TESTS) test/catch/catch.o

test-mem: $(TESTS)
	valgrind --leak-check=full --error-exitcode=1 ./test-room2
