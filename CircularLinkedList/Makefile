all: main

main: main.o CircularLinkedList.o ItemType.o
	g++ -o main main.o CircularLinkedList.o ItemType.o

main.o: main.cpp CircularLinkedList.h ItemType.h
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -c main.cpp

CircularLinkedList.o: CircularLinkedList.cpp CircularLinkedList.h
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -c CircularLinkedList.cpp

ItemType.o: ItemType.cpp ItemType.h
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -c ItemType.cpp

clean:
	rm -f ItemType
	rm -f ItemType.o 	
	rm -f CircularLinkedList
	rm -f CircularLinkedList.o
	rm -f main
	rm -f main.o