#ifndef STRANGECALCULATOR_H
#define STRANGECALCULATOR_H
#include <string>
#include "StackDouble.h"
#include "StackString.h"
#include "StackChar.h"
using namespace std;
/**
 * @brief header file of strangecalculator
 * @author Onur Ertunc
 * @date 15.05.2021
 */


string infix2prefix( const string exp );
double evaluatePrefix( const string exp );
bool isBalancedInfix( const string exp );
void evaluateInputPrefixExpression( );

int precedence( char ch );

#endif
