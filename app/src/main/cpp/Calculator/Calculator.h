//
// Created by GC2176 on 1/27/2021.
//

#ifndef ANDROIDCALCULATOR_CALCULATOR_H
#define ANDROIDCALCULATOR_CALCULATOR_H

#include "Operators.h"
#include <string>
#include <vector>
using namespace std;

class Calculator {
public:
    virtual string validate(string input)=0;
    virtual std::vector<std::string> tokenize(string inputs)=0;
    virtual string calculate(string input_expression)=0;
    void addOperatorToList();
    vector<string> getOperatorList();
    bool isOperator();
    void mapOperator(string operatorSymbol);

    void setInputExpression(string inexp){
        this->InputExpression = inexp;
    }
    string getInputExpression(){
        return this->InputExpression;
    }

    void setOutput(double d){
        this->Output = to_string(d);
    }

    string getOutput(){
        return this->Output;
    }

public:
    string InputExpression;
    string Output;
    std::vector<string> operatorList;

};

#endif //ANDROIDCALCULATOR_CALCULATOR_H
