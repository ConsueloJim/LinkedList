#include "LinkedList.h"
#include "ListException.h"
#include <cstdlib>
#include <iostream>

using namespace std;

LinkedList::LinkedList():size(0),head(NULL) {
    
}

LinkedList::LinkedList(const LinkedList& copyList):size(copyList.size) {
    if(copyList.head==NULL){
        head = NULL;
        size=0;
    }
    else {
        //copy first node
        head = new ListNode;
        head -> item = copyList.head->item; 
        
        ListNode *newPtr = head; 
        
        for(ListNode *origPtr = copyList.head->next; origPtr != NULL; origPtr = origPtr->next) {
          newPtr->next = new ListNode;
          newPtr = newPtr->next;
          newPtr->item = origPtr->item; 
        }
        newPtr->next = NULL; 
    }
}
//Assignment operator
 void LinkedList::operator=(const LinkedList& rhs) {
    ListNode *curr = head; 
    while(head != NULL)
        delete curr; 
    while(curr != NULL) {
        head = curr->next;
        delete curr;
        curr = head;  
    }
    //head = curr;
}

LinkedList::~LinkedList() {
    ListNode *curr = head;
    
    while(curr != NULL) {
        head = curr->next;
        delete curr;
        curr = head;
    }
}   //End Destructor
//Empty List
bool LinkedList::isEmpty() const {
    return size == 0; 
}
//Get size of List 
int LinkedList::getLength() const {
    return size;
}

LinkedList::ListNode *LinkedList::find(int index) const {
    if((index < 1) || (index > getLength()) )
        return NULL; 
    else {
        ListNode *cur = head;
        for(int skip = 1; skip < index; ++skip)
            cur = cur->next;
        return cur;
    }
}

void LinkedList::retrieve(int index, ListItemType& dataItem) const throw(ListIndexOutOfRangeException){
    if ( (index < 1) || (index > getLength()) )
      throw ListIndexOutOfRangeException (
            "ListIndexOutOfRangeException: retrieve index out of range");
    else
    {  // get pointer to node, then data in node
      ListNode *cur = find(index);
      dataItem = cur->item;
    }  // end if
}  // end retrieve

void LinkedList::insert(int index, const ListItemType& newItem) throw(ListIndexOutOfRangeException, ListException)
{
  int newLength = getLength() + 1;

  if ( (index < 1) || (index > newLength) )
      throw ListIndexOutOfRangeException(
            "ListIndexOutOfRangeException: insert index out of range");
  else
  {  // try to create new node and place newItem in it
      try
      {
        ListNode *newPtr = new ListNode;
        size = newLength;
        newPtr->item = newItem;

// attach new node to list
  if (index == 1)
  {  // insert new node at beginning of list
    newPtr->next = head;
    head = newPtr;
  }
  else {  
      ListNode *prev = find(index-1);
            // insert new node after node
            // to which prev points
            newPtr->next = prev->next;
            prev->next = newPtr;
   }  // end if
       }  // end try
    catch (bad_alloc e)
    {
      throw ListException(
            "ListException: memory allocation failed on insert");
    }  // end catch
  }  // end if
}  // end insert

void LinkedList::remove(int index) throw(ListIndexOutOfRangeException)
{
  ListNode *cur;

  if ( (index < 1) || (index > getLength()) )
      throw ListIndexOutOfRangeException (
            "ListIndexOutOfRangeException: remove index out of range");
  else {  
      --size;
      if (index == 1)
      {  // delete the first node from the list
        cur = head;  // save pointer to node
        head = head->next;
      }

      else
      {  ListNode *prev = find(index - 1);
        // delete the node after the node to which prev points
        cur = prev->next;  // save pointer to node
        prev->next = cur->next;
      }  // end if

      // return node to system
      cur->next = NULL;
      delete cur;
      cur = NULL;
  }  // end if
}  // end remove

void LinkedList::reverse(){
    ListNode *pTempHead = head, *pRestNodes = NULL, *pNextNode = NULL; 
    
    if(head == NULL)
        return; 
    
    tail = head;
    
    pRestNodes = head->next;
    
    while(pRestNodes != NULL) {
        pNextNode = pRestNodes;
        pRestNodes = pRestNodes->next;
        pNextNode->next = pTempHead;
        pTempHead = pNextNode; 
    }
    head = pTempHead;
    tail->next = NULL;
}
void LinkedList::traverse_and_print() {
    ListNode *p = head;
    
    if(head == NULL) {
        cout << "The list is empty" << endl;
        return;
    }
    cout << "LinkedList: ";
    while(p != NULL) {
        cout << p->item << " ";
        p = p->next;
    }
    cout << endl;
}

std::ostream& operator<<(std::ostream & out, const LinkedList &aList){
    
    LinkedList::ListNode* p; 
    for(p= aList.head; p !=NULL; p = p->next) {
        out << p->item << " ";
   
   }
    return out; 
   
}
