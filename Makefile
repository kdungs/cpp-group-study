CXXFLAGS=-O3 -Wall -Werror -pedantic -std=c++11

all: main main.s

main: main.cc

main.s: main.cc
	$(CXX) $(CXXFLAGS) -S $^

clean:
	rm -f main
	rm -f main.s
