all: main

main: main.o DoublyLinkedList.o ItemType.o
	g++ -o main main.o DoublyLinkedList.o ItemType.o

main.o: main.cpp DoublyLinkedList.h ItemType.h
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -c main.cpp

DoublyLinkedList.o: DoublyLinkedList.cpp DoublyLinkedList.h
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -c DoublyLinkedList.cpp

ItemType.o: ItemType.cpp ItemType.h
	g++ -Wall -std=c++14 -g -O0 -pedantic-errors -c ItemType.cpp

clean:
	rm -f ItemType
	rm -f ItemType.o 	
	rm -f DoublyLinkedList
	rm -f DoublyLinkedList.o
	rm -f main
	rm -f main.o