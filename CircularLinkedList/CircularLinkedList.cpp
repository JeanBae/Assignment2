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

CircularLinkedList::CircularLinkedList(){
  length = 0;
  listData = nullptr;
  current = nullptr;
}
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

void CircularLinkedList::deleteItem(ItemType &item){

}

int CircularLinkedList::lengthIs() const{
  return length;
}

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
