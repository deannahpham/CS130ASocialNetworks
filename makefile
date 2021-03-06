CXX = clang++

CXXFLAGS = -std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field

BINARIES=prog3

all: ${BINARIES}

prog3: HashTable.o AdjList.o ProfileData.o BTree.o BTreeNode.o InnerNode.o LeafNode.o Main.o Organizer.o
	${CXX} $^ -o $@

clean:
	/bin/rm -f ${BINARIES} *.o