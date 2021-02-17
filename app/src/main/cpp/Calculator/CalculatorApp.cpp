//
// Created by GC2176 on 1/27/2021.
//

#include "CalculatorApp.h"

using namespace std;
CalculatorApp CalculatorApp::calculatorapp;

CalculatorApp& CalculatorApp::Get(string input,string mode) {
    calculatorapp.setInputString(input);
    calculatorapp.setCalMode(mode);
    calculatorapp.setCal();
    return calculatorapp;
}

void CalculatorApp::setInputString(string input) {
    InputString = input;
}

std::string CalculatorApp::getInputString() {
    return InputString;
}

void CalculatorApp::setCalMode(string mode) {
    CalMode = mode;
}

std::string CalculatorApp::getCalMode() {
    return CalMode;
}

void CalculatorApp::setCal() {
    string cm = this->getCalMode();
    if (cm == "sci")
    {
        Cal = new ScientificCalculator;
        std::cout << "set a scientific calculator" << endl;
    }
    else if (cm == "standard")
    {
        Cal = new StandardCalculator;
        std::cout << "set a standard calculator" << std::endl;
    }
}

Calculator* CalculatorApp::getCal() {
    return Cal;
}

void CalculatorApp::setCalAnswer(string answer) {
    Answer = answer;
}

string CalculatorApp::getCalAnswer() {
    string inputStr = calculatorapp.getInputString();
    string answer = calculatorapp.Cal->calculate(inputStr);
    calculatorapp.setCalAnswer(answer);
    return calculatorapp.Answer;

}

