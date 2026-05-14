# author: Danila "akshin_" Axyonov

.PHONY: clean

CXX = g++
CXXFLAGS = -std=c++17 -O0 -Wall -Wextra -Wpedantic -Werror

bin/main.out: obj/graph.o obj/main.o
	$(CXX) $(CXXFLAGS) obj/graph.o obj/main.o -o $@

obj/graph.o: include/graph.hpp src/graph.cpp
	$(CXX) $(CXXFLAGS) -c src/graph.cpp -o $@

obj/main.o: include/graph.hpp src/main.cpp
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o $@

clean:
	rm -rf obj/* bin/*
