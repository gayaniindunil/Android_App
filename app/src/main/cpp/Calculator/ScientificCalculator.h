//
// Created by GC2176 on 1/27/2021.
//

#ifndef ANDROIDCALCULATOR_SCIENTIFICCALCULATOR_H
#define ANDROIDCALCULATOR_SCIENTIFICCALCULATOR_H


#include "Calculator.h"
#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <sstream>
#include <list>
#include <map>
#include <iterator>
#include <stdlib.h>

using namespace std;

class ScientificCalculator: public Calculator {
public:
    ScientificCalculator();
    ~ScientificCalculator();

    string validate(string input) override ;

    string calculate(string input_expression) override ;

    bool isParenthesis(const string &token);

    bool isOperator(const string &token);

    bool isAssociative(const string &token, const int &type);

    int cmpPrecedence(const string &token1, const string &token2);

    bool getPostfixExpression( const vector<string>& inputTokens,const int& size,vector<string>& strArray );

    double postfixExpToDouble(vector<string> *tokens, int tokenVectorLength);

    vector<string> tokenize(string expression) override ;

    double calOperatorTemp(double a, double b, string oper);
};


#endif //ANDROIDCALCULATOR_SCIENTIFICCALCULATOR_H
