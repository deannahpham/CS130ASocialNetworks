CXX = clang++

CXXFLAGS = -std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field

BINARIES=prog3

all: ${BINARIES}

prog2: Person.o HashTable.o BTree.o Graph.o Main.o
	${CXX} $^ -o $@

clean:
	/bin/rm -f ${BINARIES} *.o