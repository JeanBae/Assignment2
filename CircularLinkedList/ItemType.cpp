/**
 * @author Stone Daniel
 * @author Jean Bae
 */

#include <cstdlib>
#include <iostream>
#include "ItemType.h"

using namespace std;

/**
 * ItemType constructor
 */
ItemType::ItemType()
{
  
}

/* *
 * Compares item being passed to item in the list
 * @param ItemType &item
 * @return RelationType enum
 */
RelationType ItemType::compareTo(ItemType &item)
{ 
  if(value < item.getValue())
    {
      return LESS;
    }
  
  else if(value > item.getValue())
    {
      return GREATER;
    }
  
  else
    {
      return EQUAL;
    }
}

/**
 * Prints value of item
 */
void ItemType::print()
{
    cout << value;
}

/**
 * Initializes item with number passed in
 * @param int number
 */
void ItemType::initialize(int number)
{
  value = number;
  
}

/**
 * Gets value of item
 * @return int
 */
int ItemType:: getValue() const
{
  return value;
}

