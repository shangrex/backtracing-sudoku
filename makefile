all: solve transform generate
solve: solve.o sudoku.o
	g++ solve.o sudoku.o -o solve
solve.o: solve.cpp sudoku.cpp
	g++ -c solve.cpp sudoku.cpp 
generate: generate.o sudoku.o
	g++ generate.o sudoku.o -o generate
generate.o: generate.cpp sudoku.cpp
	g++ -c generate.cpp sudoku.cpp
transform: transform.o sudoku.o
	g++ transform.o sudoku.o -o transform
transform.o: transform.cpp sudoku.cpp
	g++ -c transform.cpp sudoku.cpp
clean:
	rm -f *.o
