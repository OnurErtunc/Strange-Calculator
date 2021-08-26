#ifndef STACKCHAR_H
#define STACKCHAR_H
using namespace std;
/**
 * @brief Stack Implementation
 * @author Onur Ertunc 21802760 Section 1
 * @date 15.05.2021
 * 
 */
class StackChar {

    public: 
        StackChar(); 
        StackChar( const StackChar& aStack );
        ~StackChar();

        bool isEmpty() const;
        bool push( char newItem );
        bool pop();
        bool pop( char& stackTop );
        bool getTop( char& stackTop ) const;

    private:
        struct StackNode {
            char item;
            StackNode *next;
        };

        StackNode *topPtr;
};
#endif