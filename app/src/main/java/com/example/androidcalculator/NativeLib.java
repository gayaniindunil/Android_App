package com.example.androidcalculator;

public class NativeLib {
    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    public native String stringFromJNI();

    public native boolean InputToJNI(String input,String mode);

    public native String outputFromJNI(String input,String mode);
}
