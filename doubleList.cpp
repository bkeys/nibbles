#include <iostream>

using namespace std;

struct node {
  int x;
  int y;
  
  node *prev;
  node *next;
};


int main(int argc, char ** argv) {
  
  node head;

  head.x = 5;
  head.y = 5;
  head.prev = NULL;
 
  node * cursor = &head;
  
  // Build our linked list
  char response = 'y'; 
  while(response != 'n') {    
    // create new node in this doubly linked list and assign the 'prev' and 'next pointers accordingly
    cursor->next = new node;
    cursor->next->prev = cursor;
    
    // Increment cursor
    cursor = cursor->next;

    // Assign data in linked list
    cursor->x = (cursor->prev->x) + 1;
    cursor->y = (cursor->prev->y) + 1;    

    cout << "Would you like to make another node in your list(y/n)?\n";
    cin >> response;
  }
  cursor-> next = NULL;

  // Now iterate through the linked list we created.
  cout << "Listing members of the doubly linked list...\n";
  cursor = &head;
  while(cursor->next) {
    cout << "This node has:\n" 
	 << "\tX: " << cursor->x << endl
	 << "\tY: " << cursor->y << endl;
    cursor = cursor->next;
  }
  
  

  return 1;
}

