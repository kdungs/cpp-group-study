CXX=clang++
CXXFLAGS=-O3 -Werror -Weverything -pedantic -Wno-c++98-compat -std=c++11

test_group.o: test_group.cc

test_variadic: test_variadic.cc

test_variadic.s: test_variadic.cc
	$(CXX) $(CXXFLAGS) -S $^

clean:
	rm -f test_group.o
	rm -f test_variadic
	rm -f test_variadic.s
