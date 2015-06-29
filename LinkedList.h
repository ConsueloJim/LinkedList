
#ifndef LINKEDLIST_H
#define	LINKEDLIST_H

#include "ListException.h"

typedef int ListItemType;

class LinkedList {
    
public:
    
    LinkedList();       //Default Constructor
    LinkedList(const LinkedList & copyList);    //Copy Constructor
    void operator=(const LinkedList& rhs); 
    ~LinkedList();      //Destructor
    
    bool isEmpty() const; 
    int getLength() const; 
    void insert(int index, const ListItemType& newItem)
         throw(ListIndexOutOfRangeException, ListException);
    void remove(int index) 
         throw(ListIndexOutOfRangeException);
    void retrieve(int index, ListItemType& dataItem)  
         const throw(ListIndexOutOfRangeException); 
    void reverse();
    void traverse_and_print(); 
    friend std::ostream& operator<<(ostream &out, const LinkedList & aList);
    
private:
    
    struct ListNode {
        ListItemType item;
        
        ListNode *next;
    };
    
    int size;
    
    ListNode *head; 
    
    ListNode *tail; 
    
    ListNode *find(int index) const; 
};

#endif	/* LINKEDLIST_H */

