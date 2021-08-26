#ifndef STACKSTRING_H
#define STACKSTRING_H
#include <string>
using namespace std;
/**
 * @brief Stack Implementation
 * @author Onur Ertunc 21802760 Section 1
 * @date 15.05.2021
 * 
 */
class StackString {

    public: 
        StackString(); 
        StackString( const StackString& aStack );
        ~StackString();

        bool isEmpty() const;
        bool push( string newItem );
        bool pop();
        bool pop( string& stackTop );
        bool getTop( string& stackTop ) const;

    private:
        struct StackNode {
            string item;
            StackNode *next;
        };

        StackNode *topPtr;
};
#endif