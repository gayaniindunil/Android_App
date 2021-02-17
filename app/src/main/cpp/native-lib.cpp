#include <alloca.h>
//
// Created by GC2176 on 1/20/2021.
//
#include <iostream>
#include <string>
#include <jni.h>

#include "Calculator/CalculatorApp.h"
#include "Calculator/ScientificCalculator.h"


extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_androidcalculator_NativeLib_stringFromJNI(JNIEnv *env, jobject thiz) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_example_androidcalculator_NativeLib_InputToJNI(JNIEnv *env, jobject thiz, jstring input,
                                                  jstring mode) {
    // TODO: implement InputToJNI()
//
//
//    char *inputstr = const_cast <char *> (env->GetStringUTFChars(input,0));
//    char *inputmode = const_cast <char *>(env->GetStringUTFChars(mode, 0));

//    In = env->GetStringUTFChars(input, NULL);
//    Inmode = env->GetStringUTFChars(mode,NULL);

    bool ret = false;

//    if (!In.empty() && !Inmode.empty()) {
//        // Correct Data got from JAVA
//        ret = true;
//    } else {
//        // Wrong Data got from JAVA
//        ret = false;
//    }

    return ret;
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_androidcalculator_NativeLib_outputFromJNI(JNIEnv *env, jobject , jstring inputs, jstring mode) {
//    string Inmode = "standard";
//    string In = "2+3*3-5";
    const char* In = env->GetStringUTFChars(inputs,NULL);
    const char* Inmode = env->GetStringUTFChars(mode,NULL);

//    CalculatorApp& instance = CalculatorApp::Get(input,mode);
    CalculatorApp& instance = CalculatorApp::Get(In,Inmode);
    string output = instance.getCalAnswer();
    cout << "printing output in main " << output << endl;
    return env->NewStringUTF(output.c_str());
}