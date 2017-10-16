/**
 * @author Stone Daniel 
 * @author Jean Bae
 * Driver file 
 */

#include <fstream>
#include <iostream>
#include "CircularLinkedList.h"


using std::cout;
using std::endl;
using std::cin;
using std::string;

int main(int argc, char** argv){

  CircularLinkedList list;
  ItemType item;
  int input;
  std::fstream fs;

  string command = "";
  int num;
  fs.open(argv[1], std::fstream::in);
  if(fs.is_open())
    {
      fs >> input;
      while(!fs.eof())
	{
	  item.initialize(input);
	  list.insertItem(item);
	  fs >> input;
	}
    }
  else
    {
      std::cout << "File could not be opened. " <<"Try again." <<endl;
      return 0;
    }

  cout << "Commands - insert (i), delete (d), length (l), print (p), quit (q)" <<endl;
  do{
    cout << "Enter a command: ";
    cin >> command;
    if(command == "q")
      {
	cout << "Quitting program..." <<endl;
	return 0;
      }
    
    else if(command == "i")
      {
	cout << "Number to insert: ";
	cin >> num;
	if(cin.fail())
	  {
	    cin.clear();  
	    cin.ignore();
	    cout << "Invalid Input" << endl;
	  }
	else
	  {
	    item.initialize(num);
	    list.insertItem(item);
	    list.print();
	  }
      }
    else if(command == "d")
      {
	if(list.lengthIs() == 0)
          {
            cout << "List is Empty" << endl;
            continue;
          }
	cout << "Number to delete: ";
	cin >> num;
	if(cin.fail())
	  {
	    cin.clear();  
	    cin.ignore();
	    cout << "Invalid Input" << endl;
	  }
	else
	  {
	    item.initialize(num);
	    list.deleteItem(item);
	    list.print();
	  }
      }    
    else if(command == "l")
      {
	cout << "Length of List: " << list.lengthIs() << endl;
      }
    else if(command == "p")
      {
	list.print();
      }
    else
      {
	cout << "Command not recognized. Try again" <<endl;	
      }


  }while(true);

}
