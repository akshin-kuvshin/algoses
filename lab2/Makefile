# author: Danila "akshin_" Axyonov

.PHONY: clean

CXX = g++
CXXFLAGS = -std=c++11 -O0 -Wall -Wextra -Wpedantic -Werror

bin/main.out: obj/intTree.o obj/main.o
	$(CXX) $(CXXFLAGS) obj/intTree.o obj/main.o -o $@

obj/intTree.o: include/intNode.hpp include/intTree.hpp src/intTree.cpp
	$(CXX) $(CXXFLAGS) -c src/intTree.cpp -o $@

obj/main.o: include/intNode.hpp include/intTree.hpp src/main.cpp
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o $@

clean:
	rm -rf obj/* bin/*
