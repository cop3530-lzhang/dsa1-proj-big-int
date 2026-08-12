CXX = g++
CXXFLAGS = -g -std=c++14 -Wall -Werror=return-type  -Werror=uninitialized

SRCS = $(wildcard *.cpp)
HEADERS = $(wildcard *.hpp)
OBJECTS = $(SRCS:%.cpp=%.o)

CATCH = test/catch/catch.o
TEST_SRCS = $(wildcard test/*.cpp)
TESTS = $(TEST_SRCS:test/%.cpp=%)

main: $(OBJECTS)
	$(CXX) -o $@ $^

clean:
	rm -rf main.dSYM
	$(RM) *.o *.gc* test/*.o test/*.gc* *.dSYM $(TESTS) core main $(CATCH)

test-all: $(TESTS)

test/catch/catch.o: test/catch/catch.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

test-mem: test-2-stack
	valgrind --error-exitcode=1 --leak-check=full ./test-2-stack

test-1-node: stack.o test/test-1-node.o
test-2-stack: stack.o test/test-2-stack.o
test-3-operand: stack.o operand.o test/test-3-operand.o
test-4-arithmetic-expression: stack.o operand.o arithmetic-expression.o test/test-4-arithmetic-expression.o
test-5a-big-integer-arithmetic: stack.o operand.o arithmetic-expression.o big-integer-arithmetic.o test/test-5a-big-integer-arithmetic.o
test-5b-big-integer-arithmetic: stack.o operand.o arithmetic-expression.o big-integer-arithmetic.o test/test-5b-big-integer-arithmetic.o
test-6-expression-reader: stack.o operand.o arithmetic-expression.o big-integer-arithmetic.o expression-reader.o test/test-6-expression-reader.o

$(TESTS): $(CATCH)
	$(CXX) $(CXXFLAGS) -o $@ $^
	./$@ --success
