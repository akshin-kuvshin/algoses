# author: Danila "akshin_" Axyonov

.PHONY: clean

CXX = g++
CXXFLAGS = -std=c++11 -O0 -Wall -Wextra -Wpedantic -Werror

bin/main.out: include/Sort.hpp obj/ContestParticipant.o obj/main.o
	$(CXX) $(CXXFLAGS) obj/ContestParticipant.o obj/main.o -o $@

obj/ContestParticipant.o: include/ContestParticipant.hpp src/ContestParticipant.cpp
	$(CXX) $(CXXFLAGS) -c src/ContestParticipant.cpp -o $@

obj/main.o: include/Sort.hpp include/ContestParticipant.hpp src/main.cpp
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o $@

clean:
	rm -rf obj/* bin/*
