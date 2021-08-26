#ifndef STACKDOUBLE_H
#define STACKDOUBLE_H
using namespace std;
/**
 * @brief Stack Implementation
 * @author Onur Ertunc 
 * @date 15.05.2021
 * 
 */
class StackDouble {

    public: 
        StackDouble(); 
        StackDouble( const StackDouble& aStack );
        ~StackDouble();

        bool isEmpty() const;
        bool push( double newItem );
        bool pop();
        bool pop( double& stackTop );
        bool getTop( double& stackTop ) const;

    private:
        struct StackNode {
            double item;
            StackNode *next;
        };

        StackNode *topPtr;
};
#endif
