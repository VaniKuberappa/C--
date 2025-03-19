
CXX = g++
CXXFLAGS = -std=c++11 -pthread -lgtest_main -lgtest

all: pgm tests

pgm: Task_DT.cpp
    $(CXX) $(CXXFLAGS) -o pgm Task_DT.cpp

tests: tests.cpp Task_DT.cpp
    $(CXX) $(CXXFLAGS) -o tests tests.cpp Task_DT.cpp

clean:
    rm -f pgm tests
