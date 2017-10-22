/*
Stone Daniel Jean Bae
 */
#ifndef DoublyLinkedList_H
#define DoublyLinkedList_H
#include "ItemType.h"
struct NodeType
{
  ItemType info;
  NodeType *next;
  NodeType *prev;
};

class DoublyLinkedList
{
 public:
  DoublyLinkedList();
  ~DoublyLinkedList();
  int lengthIs() const;
  void retrieveItem(ItemType &item, bool &found);
  void insertItem(ItemType &item);
  void deleteItem(ItemType &item);
  void resetList();
  void getNextItem(ItemType &item);
  void makeEmpty();
  void print();

 private:
  int length;
  NodeType *head;
  NodeType *current;
  NodeType *findNode(ItemType &item);
  void getNextNode();

};
#endif

