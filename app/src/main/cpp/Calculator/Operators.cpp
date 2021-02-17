//
// Created by GC2176 on 2/2/2021.
//

#include "Operators.h"

template<typename T1>
double Addition(T1 a, T1 b) {
    return  a+b;
}

template<typename T1, typename T2>
double Subtraction(T1 a, T2 b) {
    return  (double)a-b;
}

template<typename T1, typename T2>
double Multiplication(T1 a, T2 b) {
    return  (double)a*b;
}

template<typename T1, typename T2>
double Division(T1 a, T2 b) {
    return (double) a/b;
}

template<typename T1, typename T2>
double Percent(T1 a, T2 b) {
    return (double) a*(b/100);
}

template<typename T>
double Sin(T a) {
    return (double) sin(a);
}

template<typename T>
double Cos(T a) {
    return (double) cos(a);
}

template<typename T>
double Tan(T a) {
    return (double) tan(a);
}

template<typename T>
double Log(T a) {
    return  (double) log(a);
}

template<typename T>
double Squareroot(T a) {
    return  (double) sqrt(a);
}

template<typename T1, typename T2>
double Power(T1 a, T2 b) {
    return (double)pow(a,b);
}

