//
// Created by GC2176 on 1/27/2021.
//

#ifndef ANDROIDCALCULATOR_CALCULATORAPP_H
#define ANDROIDCALCULATOR_CALCULATORAPP_H

#include "Calculator.h"
#include "ScientificCalculator.h"
#include "StandardCalculator.h"
#include <string>
#include <iostream>

using namespace std;

class CalculatorApp {
public:
    CalculatorApp(const CalculatorApp&) = delete;
    static CalculatorApp& Get(string input,string mode);
    void setInputString(string input);
    std::string getInputString();
    void setCalMode(string mode);
    std::string getCalMode();
    void setCalAnswer(string answer);
    string getCalAnswer();
    void setCal();
    Calculator* getCal();

private:
    static CalculatorApp calculatorapp;
    string InputString;
    string CalMode;
    string Answer;
    Calculator* Cal = NULL;
    CalculatorApp(){}
};



#endif //ANDROIDCALCULATOR_CALCULATORAPP_H
