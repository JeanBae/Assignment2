/**
 * This is the CircularLinkedList class 
 * @author Stone Daniel
 * @author Jean Bae
 */

#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H
#include "ItemType.h"

template<class ItemType>
struct NodeType{
  ItemType info;
  NodeType *next;
};


class CircularLinkedList{

 public:
  CircularLinkedList();
  ~CircularLinkedList();
  void FindItem(NodeType<ItemType>* listData, ItemType item, NodeType<ItemType>*& location, NodeType<ItemType>*& predLoc, bool& found);
  void insertItem(ItemType &item);
  void deleteItem(ItemType &item);
  int lengthIs() const;
  void print();

 private:
  int length;
  NodeType<ItemType> *listData;
  NodeType<ItemType> *current;

};
#endif
