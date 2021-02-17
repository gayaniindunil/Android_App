//
// Created by GC2176 on 1/27/2021.
//
//
#include "Calculator.h"

void Calculator::addOperatorToList() {

}

vector<string> Calculator::getOperatorList() {
    return vector<string>();
}

bool Calculator::isOperator() {
    return false;
}

void Calculator::mapOperator(string operatorSymbol){
    string operation;
    if  (operatorSymbol == "+" ) {
            operation = "Addition";
    }
    else if(operatorSymbol == "-" ){
        operation = "Subtraction";
    }
    else if(operatorSymbol == "*" ){
        operation = "Multiplication";
    }
    else if(operatorSymbol == "/" ){
        operation = "Division";
    }
    else if(operatorSymbol == "%" ){
        operation = "Percent";
    }
    else if(operatorSymbol == "sin" ){
        operation = "Sin";
    }
    else if(operatorSymbol == "cos" ){
        operation = "Cos";
    }
    else if(operatorSymbol == "tan" ){
        operation = "Tan";
    }
    else if(operatorSymbol == "log" ){
        operation = "Log";
    }
    else if(operatorSymbol == "pow" ){
        operation = "Power";
    }
    else if(operatorSymbol == "sqrt" ){
        operation = "Squareroot";
    }
}

//string Calculator::validate(string input) {
//    return std::string();
//}
//
//std::vector<std::string> Calculator::tokenize(string inputs) {
//    return std::vector<std::string>();
//}
//
//string Calculator::calculate(string input_expression) {
//    return std::string();
//}


