//
// Created by GC2176 on 2/2/2021.
//

#ifndef ANDROIDCALCULATOR_OPERATORS_H
#define ANDROIDCALCULATOR_OPERATORS_H
#include <string>

//class Operator{
//private:
//    std::string name;
//    std::string id;
//public:
//    void operation();
//};

template<typename T1, typename T2>
double Addition(T1 a, T2 b);

template<typename T1, typename T2>
double Subtraction(T1 a, T2 b);

template<typename T1, typename T2>
double Multiplication(T1 a, T2 b);

template<typename T1, typename T2>
double Division(T1 a, T2 b);

template<typename T1, typename T2>
double Percent(T1 a, T2 b);

template<typename T>
double Sin(T a);

template<typename T>
double Cos(T a);

template<typename T>
double Tan(T a);

template<typename T>
double Log(T a);

template<typename T>
double Squareroot(T a);

template<typename T1, typename T2>
double Power(T1 a, T2 b);

#endif //ANDROIDCALCULATOR_OPERATORS_H
