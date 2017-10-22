/**
 * @author Stone Daniel
 * @author Jean Bae
 *
 * This is implements the functions of the LinkedList class
 */

#include "DoublyLinkedList.h"
#include "ItemType.h"
#include <iostream>
#include <cstdlib>

using namespace std;

/**
 * Constructor, sets length to 0, head and current pointers to NULL
 */
DoublyLinkedList::DoublyLinkedList()
{
  this->length = 0;
  this->head = nullptr;
  this->current = nullptr;
}

/**
 * Destructor, deallocates memory
 */
DoublyLinkedList::~DoublyLinkedList()
{
  makeEmpty();
}

/**
 * @return The length of LinkedList
 */
int DoublyLinkedList::lengthIs() const
{
  return length;
}

/**
 * Sets is found to true if item is found
 * @param ItemType and bool
 */
void DoublyLinkedList::retrieveItem(ItemType &item, bool &found)
{
  bool moreToSearch;
  NodeType* location;
  location = head;
  found = false;
  moreToSearch = (location != NULL);
  
  while(moreToSearch && !found)
    {
      switch(item.compareTo(location ->info))
	{
	case GREATER: location = location ->next;
	  moreToSearch = (location!= NULL);
	  break;
  
	case EQUAL: found = true;
	  break;
  
	case LESS: moreToSearch = false;
	  break;
	}
    }
}
/**
 * Inserts item in proper location of the linked list
 * @param ItemType
 */
void DoublyLinkedList::insertItem(ItemType &item)
{
  //resetList();
  NodeType * newNode = new NodeType;
  current = head;
  newNode->info = item;
  if(head == NULL)
    {
      head = newNode;
      length++;
      return;
    }
  if(item.compareTo(head->info) == LESS)
    {
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
      length++;
      return;
    }
  while(current->next)
    {
      if(item.compareTo(current->info) == GREATER)
	  getNextNode();  
      if(item.compareTo(current->info) == EQUAL)
	{
	  delete newNode;
	  return;
	}
      if(item.compareTo(current->info) == LESS)
	  break;
    }

  if(item.compareTo(current->info) == LESS)
    {
      newNode->next = current;
      newNode->prev = current->prev;
      current->prev->next = newNode;
      current->prev = newNode;
    }
  else if(item.compareTo(current->info) == GREATER)
    {
      current->next = newNode;
      newNode->prev = current;
    }
  else
    {
      delete newNode;
      return;
    }

  length++;
}

/**
 * Deletes item from the linked list
 * @param ItemType
 */
void DoublyLinkedList::deleteItem(ItemType &item)
{

  current = head;
  while(current)
    {
      if(current->info.compareTo(item) == EQUAL)
	{
	  if(current != head)
	    {
	      current->prev->next = current->next;
	      if(current->next)
		current->next->prev = current->prev;
	      delete current;
	      length--;
	      return;
	    }
	  else
	    {
	      head = current->next;
	      delete current;
	      length--;
	      return;
	    }
	}
      current=current->next;
    }
  cout << "item not found" << endl;
  /*NodeType *finder = findNode(item);
  if(finder != NULL)
    {
      delete finder;
      finder = nullptr;
      length--;
    }
  else
  cout << "item not found" <<endl;*/
}

/**
 * Resets current pointer to nullptr
 */
void DoublyLinkedList::resetList()
{
  this->current = nullptr;
}

/**
 * Gets next item from the list
 * @param ItemType
 */
void DoublyLinkedList::getNextItem(ItemType &item)
{
  NodeType *temp = current;
  getNextNode();
  if(current != nullptr)
    {
  
      item = current->info;
      item.print();
    }
  else
    {
      cout << "End of List";
      current = temp;
    }
}

/**
 * Removes all items from list
 */
void DoublyLinkedList::makeEmpty()
{
  NodeType* temp;
  current = this->head;

  while(current != nullptr)
    {
      temp = current->next;
      delete current;
      current = temp;
    }
  length = 0;
  head = nullptr;
  resetList();
}

/**
 * Prints entire list
 */
void DoublyLinkedList::print()
{
  this->current = head;
  cout << "[ ";
  while(current != nullptr)
    {
      this->current->info.print();
      
      if(current->next!= NULL)
	{
	  cout << ", ";

	}
      getNextNode();
    }
  cout << " ]" << endl;
  
}

/**
 * Gets the next node in the list by moving the current pointer
 */
void DoublyLinkedList::getNextNode()
{
  if(current == nullptr)
    current = head;
  else
    current = current->next;
  

}

/**
 * Finds node containing the item passed in
 * @param ItemType
 * @ return NodeType pointer
 */
NodeType *::DoublyLinkedList::findNode(ItemType &item)
{
  current = head;
  NodeType* temp;
  if(item.compareTo(head->info) == EQUAL)
    {
      temp = current;
      head = head->next;
    }
  else
    {
      while((current->next != nullptr) && ((item.compareTo(current->next->info)) != EQUAL))
	getNextNode();
      if(current->next != nullptr)
	{
	  temp = current->next;
	  current->next = (current->next)->next;
	}
      else
	{
	  temp = nullptr;
	}
    }
  return temp;

}
