//
// Created by GC2176 on 1/27/2021.
//

#ifndef ANDROIDCALCULATOR_STANDARDCALCULATOR_H
#define ANDROIDCALCULATOR_STANDARDCALCULATOR_H


#include "Calculator.h"
#include "Operators.h"
#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <stack>
#include <queue>
#include <sstream>

#include <stdlib.h>
using namespace std;

class StandardCalculator: public Calculator {
public:
    StandardCalculator();
    ~StandardCalculator();

    string validate(string input) override ;
    std::vector<std::string>  tokenize(string inputs) override ;
    string calculate(string input_expression) override ;

    bool isOperator( const std::string& token);
    queue<string> getPostfixExpression(vector<string> tokens);
    double postfixExpToDouble(queue<string> *postFixExp,int expressionLength);

    double calOperatorTemp(double a, double b, string oper);

    vector<string> tokenize1(string inputs);
};


#endif //ANDROIDCALCULATOR_STANDARDCALCULATOR_H
