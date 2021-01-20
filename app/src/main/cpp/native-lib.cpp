//
// Created by GC2176 on 1/20/2021.
//

#include <alloca.h>

#include <iostream>
#include <string>
#include <jni.h>

extern "C"
JNIEXPOT jstring JNICALL
Java_com_example_androidcalculator_NativeLib_stringFromJNI(JNIEnv *env, jobject thiz) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_example_androidcalculator_NativeLib_InputToJNI(JNIEnv *env, jobject thiz, jstring input,
                                                  jstring mode) {
    // TODO: implement InputToJNI()


    char *inputstr = const_cast <char *> (env->GetStringUTFChars(input,0));
    char *inputmode = const_cast <char *>(env->GetStringUTFChars(mode, 0));

    int ret = 0;

    if (inputstr != NULL && inputmode != NULL) {
        // Correct Data got from JAVA
        ret = 1;
    } else {
        // Wrong Data got from JAVA
        ret = 0;
    }

    return ret;
}

extern "C"
JNI
Java_com_example_androidcalculator_NativeLib_outputFromJNI(JNIEnv *env, jobject thiz) {
    // TODO: implement outputFromJNI()
    double r = 5.0;
    std::string result = std::to_string(r);
    return env->NewStringUTF(result.c_str());
}