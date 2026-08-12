SHELL := /bin/bash
CXX = g++
CXXFLAGS = -g -std=c++14 -Wall -Werror=return-type -Werror=uninitialized -Wno-sign-compare
RM = rm -rf

SRCS = $(wildcard *.cpp)
HEADERS = $(wildcard *.hpp)
OBJECTS = $(SRCS:%.cpp=%.o)

CATCH = test/catch/catch.o
TESTS = test-1-node test-2-stack test-3-operand test-4-arithmetic-expression test-5a-big-integer-arithmetic test-5b-big-integer-arithmetic test-6-expression-reader

all: main $(TESTS)

main: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

test-all: $(TESTS)

test/catch/catch.o: test/catch/catch.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

test-1-node: stack.o test/test-1-node.o $(CATCH)
	$(CXX) $(CXXFLAGS) -o $@ $^
	./$@ --success

test-2-stack: stack.o test/test-2-stack.o $(CATCH)
	$(CXX) $(CXXFLAGS) -o $@ $^
	./$@ --success

test-3-operand: stack.o operand.o test/test-3-operand.o $(CATCH)
	$(CXX) $(CXXFLAGS) -o $@ $^
	./$@ --success

test-4-arithmetic-expression: stack.o operand.o arithmetic-expression.o test/test-4-arithmetic-expression.o $(CATCH)
	$(CXX) $(CXXFLAGS) -o $@ $^
	./$@ --success

test-5a-big-integer-arithmetic: stack.o operand.o arithmetic-expression.o big-integer-arithmetic.o test/test-5a-big-integer-arithmetic.o $(CATCH)
	$(CXX) $(CXXFLAGS) -o $@ $^
	./$@ --success

test-5b-big-integer-arithmetic: stack.o operand.o arithmetic-expression.o big-integer-arithmetic.o test/test-5b-big-integer-arithmetic.o $(CATCH)
	$(CXX) $(CXXFLAGS) -o $@ $^
	./$@ --success

test-6-expression-reader: stack.o operand.o arithmetic-expression.o big-integer-arithmetic.o expression-reader.o test/test-6-expression-reader.o $(CATCH)
	$(CXX) $(CXXFLAGS) -o $@ $^
	./$@ --success

test-mem: test-2-stack
	valgrind --error-exitcode=1 --leak-check=full ./test-2-stack

clean:
	$(RM) *.o *.gc* test/*.o test/*.gc* *.dSYM $(TESTS) core main $(CATCH)

.PHONY: all main test-all test-mem clean test-1-node test-2-stack test-3-operand test-4-arithmetic-expression test-5a-big-integer-arithmetic test-5b-big-integer-arithmetic test-6-expression-reader
