#include <string>
#include "StackDouble.h"
#include "StackString.h"
#include "StackChar.h"
#include "StrangeCalculator.h" 
#include <iostream>
using namespace std;
/**
 * @brief global functions
 * @author Onur Ertunc
 * @date 15.05.2021
 * 
 */

/**
 * @brief evaluates a prefix
 * 
 * @param exp 
 * @return double 
 */
double evaluatePrefix(string exp) {
   
   StackDouble operandStack;

   int size = exp.size() - 1;
   
   for (int i = size; i >= 0; i--) {
       char ch = exp.at(i);
      if (isdigit(ch))
         operandStack.push(ch - '0');
      else {
         double o1;
         operandStack.pop(o1);
         double o2;
         operandStack.pop(o2);
         if( ch == '+')
            operandStack.push(o1 + o2);
         else if( ch == '-')
            operandStack.push(o1 - o2);
         else if( ch == '*')
            operandStack.push(o1 * o2);
         else if( ch == '/')
            operandStack.push(o1 / o2);
      }
   }
   double res;
   operandStack.pop(res);
   return res;
}

/**
 * @brief checks whether the infix string is balanced or not
 * 
 * @param exp 
 * @return true 
 * @return false 
 */
bool isBalancedInfix( const string exp ) {

    StackChar balanceStack;

    int size = exp.size();

    for (int i = 0; i < size; i++ ) {
        char ch = exp.at(i);
        if ( balanceStack.isEmpty() && ch == ')') {
            return false;
        }
        else {
            if ( ch == '(' ) {
                balanceStack.push(ch);
            }
            else if ( ch == ')' ) {
                balanceStack.pop();
            }
        }
    }

    bool res = balanceStack.isEmpty();
    if ( !res ) {
        while ( !balanceStack.isEmpty() ) {
            balanceStack.pop();
        }
    }

    return res;
}

/**
 * @brief helper function to determine the precedence of operators
 * 
 * @param ch 
 * @return int 
 */
int precedence( char ch ) {
    if ( ch == '*' || ch == '/' ) {
        return 2;
    }
    else if ( ch == '+' || ch == '-' ) {
        return 1;
    }
    return 0;
}


/**
 * @brief infix to prefix converter
 * 
 * @param exp 
 * @return string 
 */
string infix2prefix( const string exp ) {

    StackChar operatorStack;
    StackString operandStack;

    for ( int i = 0; i < exp.size(); i++ ) {
        char ch = exp.at(i);

        if ( ch == '(' ) {
            operatorStack.push(ch);
        }
        else if ( ch == ')' ) {
            char t;
            operatorStack.getTop(t);
            while ( !operatorStack.isEmpty() && t != '(' ) {
                
                string op1;
                operandStack.pop(op1);

                string op2;
                operandStack.pop(op2);

                char ope;
                operatorStack.pop(ope);

                operandStack.push(ope + op2 + op1);
                operatorStack.getTop(t);
            }
            operatorStack.pop();
        }
        else if ( !(!isalpha(ch) && !isdigit(ch)) ) {
            operandStack.push( string(1,ch) );
        }
        else {
            char t;
            operatorStack.getTop(t);
            while ( !operatorStack.isEmpty() && precedence(ch) <= precedence(t) ) {
                
                string op1;
                operandStack.pop(op1);

                string op2;
                operandStack.pop(op2);

                char ope;
                operatorStack.pop(ope);

                operandStack.push(ope + op2 + op1);
                operatorStack.getTop(t);
            }
            operatorStack.push(ch);
        }
    }
    // operatorStack is not currently released
    while ( !operatorStack.isEmpty() ) {

        string op1;
        operandStack.pop(op1);

        string op2;
        operandStack.pop(op2);

        char ope;
        operatorStack.pop(ope);

        operandStack.push(ope + op2 + op1);
    }
    string res;
    operandStack.pop(res);
    return res; 
}

/**
 * @brief evaluates Input prefix expression
 * 
 */
void evaluateInputPrefixExpression() {

    string infix = "";
    cout << "Enter an infix expression: ";
    cin >> infix;

    string infix2 = "";
    double result;
    for ( int i = 0; i < infix.size(); i++ ) {
        infix2 = infix2 + infix.at(i);
    }

    if ( !isBalancedInfix(infix2) ) {
        cout << "Not balanced!" << endl;
    }
    else {
        string prefix = infix2prefix(infix2);
        result = evaluatePrefix(prefix);
    }
    cout << "Evaluated prefix result: " << result << endl;
}





