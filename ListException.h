

#ifndef LISTEXCEPTION_H
#define	LISTEXCEPTION_H

#include <stdexcept>
#include <string>

using namespace std;

class ListIndexOutOfRangeException : public out_of_range {
public :
     ListIndexOutOfRangeException(const string & message = "")
      : out_of_range(message.c_str())
  { }  // end constructor
};    //end ListIndexOutOfRangeException

class ListException : public logic_error {
    
public :
    
    ListException(const string & message = "")
            : logic_error(message.c_str()) {}  //end constructor
};   //end ListException


#endif	/* LISTEXCEPTION_H */
