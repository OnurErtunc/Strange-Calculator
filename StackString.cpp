#include <iostream>
using namespace std;
#include "StackString.h"
/**
 * @brief Stack implementation for string
 * @author Onur Ertunc 
 * @date 15.05.2021
 * 
 */

/**
 * default constructor
 */
StackString::StackString() : topPtr(NULL) {

}

/**
 * @brief Construct a new Stack Int:: Stack Int object - copyconstructor
 * 
 * @param aStack 
 */
StackString::StackString(const StackString& aStack ) {

    if (aStack.topPtr == NULL ) {
        topPtr = NULL;
    }
    else {
        topPtr = new StackNode;
        topPtr->item = aStack.topPtr->item;

        StackNode *newPtr = topPtr;
        for ( StackNode *origPtr = aStack.topPtr->next;
                                   origPtr != NULL;
                                   origPtr = origPtr->next ) {

            newPtr->next = new StackNode;
            newPtr = newPtr->next;
            newPtr->item = origPtr->item;
        }

        newPtr->next = NULL;
    }
}

/**
 * @brief Destroy the Stack Int:: Stack Int object
 * 
 */
StackString::~StackString() {

    while ( !isEmpty() ) {
        pop();
    }
}

/**
 * @brief checks whether the stack is empty
 * 
 * @return true 
 * @return false 
 */
bool StackString::isEmpty() const {

    return topPtr == NULL;
}

/**
 * @brief pushes a new item to stack
 * 
 * @param newItem 
 * @return true 
 * @return false 
 */
bool StackString::push( string newItem ) {

    StackNode *newPtr = new StackNode;

    newPtr->item = newItem;

    newPtr->next = topPtr;
    topPtr = newPtr;

    return true;
}

/**
 * @brief pops an item from the stack
 * 
 * @return true 
 * @return false 
 */
bool StackString::pop() {

   if (isEmpty())
      return false;

   // stack is not empty; delete top
   else{   
      StackNode *temp = topPtr;
      topPtr = topPtr->next;

      // return deleted node to system
      temp->next = NULL;  // safeguard
      delete temp;
      return true;
   }
}

/**
 * @brief pops an item and returns it
 * 
 * @param stackTop 
 * @return true 
 * @return false 
 */
bool StackString::pop( string& stackTop) {

   if (isEmpty()) {
       return false;
   }
      

   // not empty; retrieve and delete top 
   else{
      stackTop = topPtr->item;
      StackNode *temp = topPtr;
      topPtr = topPtr->next;

      // return deleted node to system
      temp->next = NULL;  // safeguard
      delete temp;
      return true;
   }
}

/**
 * @brief gets the top from the stack
 * 
 * @param stackTop 
 * @return true 
 * @return false 
 */
bool StackString::getTop(string& stackTop) const {

   if (isEmpty())
      return false;

   // stack is not empty; retrieve top
   else {
      stackTop = topPtr->item;
      return true;
   }

}
