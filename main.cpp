/*******************************************************************************
 *        Name: Consuelo Jimenez
 *       Class: CSC340.02
 *      Assign: Homework 8, part 2 -- Linkedlist
 *        Date: 05.07.2015
 * 
 * Description: The purpose of this program is to demonstrate the use of 
 *              a singly-linked-list. The LinkedList interface is comprised of 
 *              LinkedList.h, LinkedList.cpp, listExcpetions.h and main.cpp. 
 *              It is designed to handle a list of integers. 
 ******************************************************************************/


#include "LinkedList.h"
#include "ListException.h"
#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    
    LinkedList list1;
    LinkedList list2; 
  
    cout << "---------- Testing the Singly Linked List Interaface -----------\n\n";
      
    cout << "Inserting numbers 1, 5, 11, 23, 55, 4, 17, 65..." << endl;
    list1.insert(1, 1);  
    list1.insert(2, 5);
    list1.insert(3, 11);
    list1.insert(4, 23);
    list1.insert(5, 55);
    list1.insert(6, 4);
    list1.insert(7, 17);
    list1.insert(8, 65); 
    
    cout << "List 1 is : " << list1 << endl;; 
    
    list1.reverse();
    cout << endl; 
    cout << "List 1 in reverse is: " << list1; 
    cout << endl; 
    cout << endl;
    cout << "The size of List 1 is : ";
    cout << list1.getLength() << endl;
    cout << endl; 
    cout << "Removing 23 from List1 ..." << endl;
    list1.remove(5);
    cout <<"List 1 is now: " << list1 << endl;
    cout << endl;
    cout << "Inserting number 23 back into List 1..." << endl;
    list1.insert(5, 23);
    cout << "List 1 is now : "  << list1 << endl; 
    cout << endl;
    cout << "The size of the list is : " << list1.getLength() << endl;
   
     
}
