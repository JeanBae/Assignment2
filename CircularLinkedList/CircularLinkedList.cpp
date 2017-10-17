/**
 * @author Stone Daniel
 * @author Jean Bae
 *
 * This implements the functions of the CircularLinkedList class
 */

#include "CircularLinkedList.h"
#include "ItemType.h"
#include <iostream>
#include <cstdlib>

using std::endl;
using std::cout;

/**
 * This is the CircularLinkedList constructor
 */
CircularLinkedList::CircularLinkedList(){
  length = 0;
  listData = nullptr;
  current = nullptr;
}
/**
 * This is the destructor
 */
CircularLinkedList:: ~CircularLinkedList(){
  NodeType<ItemType>* temp;
  current = listData;
  
  while(current != nullptr){
    temp = current->next;
    delete current;
    current = temp;
  }

  length = 0;
  listData = nullptr;
  current = nullptr;
}

/**
 * This is the FindItem function that finds the point of insertion and deletion using predLoc and location and other
 * values
 */
void CircularLinkedList::FindItem(NodeType<ItemType>* listData, ItemType item, NodeType<ItemType>*& location, NodeType<ItemType>*& predLoc, bool& found){

  bool moreToSearch = true;
  location = listData->next;
  predLoc = listData;
  found = false;

  while(moreToSearch && !found){
    if(item.compareTo(location->info) == LESS)
      moreToSearch = false;

    else if(item.compareTo(location->info) == EQUAL)
      found = true;

    else{
      predLoc = location;
      location = location->next;
      moreToSearch = (location != listData->next);
    }
  }
}

/**
 * InsertItem function that inserts node into proper location
 * @param item
 */
void CircularLinkedList::insertItem(ItemType &item){
  NodeType<ItemType> * newNode = new NodeType<ItemType>;
  NodeType<ItemType> * location;
  NodeType<ItemType> * predLoc;

  bool found;
  current = listData;

  newNode->info = item;

  if(listData != NULL){
    FindItem(listData, item, location, predLoc, found);
    
    if(found == true){
      delete newNode;
      length--;
    }

    else{
      newNode->next = predLoc->next;
      predLoc->next = newNode;
      
      //if last node in list, reassign listData
      if(listData->info.compareTo(item) == LESS)
	listData = newNode;
    }
    
    
  }
  //inserting into empty list
  else{
    listData = newNode;
    newNode->next = newNode;
  }
  length++;
}

/**
 * deleteItem function that deletes a node
 * @param item
 */
void CircularLinkedList::deleteItem(ItemType &item){
  NodeType<ItemType>* location;
  NodeType<ItemType>* predLoc;
  bool found;

  FindItem(listData, item, location, predLoc, found);
  //if only node in list
  if(predLoc == location)
    listData = NULL;

  else{
    //if last node in list
    if(location == listData)
      listData = predLoc;

    if(found == true && location != NULL)
    predLoc->next = location->next;

    else
      cout << "item not found" <<endl;

  }
  
  delete location;
  length--;
}

/**
 * This is the lenghtIs function that returns the length of the list 
 * @return int length
 */
int CircularLinkedList::lengthIs() const{
  return length;
}

/**
 * This function prints the list
 */
void CircularLinkedList::print(){
  current = listData;
  NodeType<ItemType> *front;

  cout << "[ ";  

  if(listData != nullptr){
    current = listData->next;
    front = current;
    
    do{
      current->info.print();
      if(current != listData){
	cout << ", ";
      }
      else{
	cout <<" ";
      }
      current = current->next;
    }while(current != front);
  }
  cout << "]" << endl;   
}
