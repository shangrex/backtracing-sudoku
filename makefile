SOURCE=sudoku.h sudoku.cpp generate.cpp transform.cpp solve.cpp
OBJECT=sudoku.o sudoku.h
CXXFLAGS=-g -Wall -std=c++0x -Ofast
CXX=g++
EXECUTABLE=generate transform solve

all:$(SOURCE) $(EXECUTABLE)

solve:solve.o $(OBJECT)
	$(CXX) -o solve $(CXXFLAGS) solve.o sudoku.o

generate:generate.o $(OBJECT)
	$(CXX) -o generate $(CXXFLAGS) generate.o sudoku.o

transform:transform.o $(OBJECT)
	$(CXX) -o transform $(CXXFLAGS) transform.o sudoku.o

%.o:%.cpp
	$(CXX) -c $< $(CXXFLAGS)

clean:
	rm *.o $(EXECUTABLE)
