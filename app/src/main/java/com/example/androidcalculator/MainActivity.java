package com.example.androidcalculator;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import java.util.Arrays;

public class MainActivity extends AppCompatActivity {

    EditText et1;
    boolean isNewOperation;
    private NativeLib nativeLib;
    String calMode;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        et1 = findViewById(R.id.editText);
        isNewOperation = true;
        nativeLib = new NativeLib();
        calMode = "standard";
//
//        String stringFromJNI = nativeLib.stringFromJNI();
//        TextView tv = findViewById(R.id.editTextOutput);
//        tv.setText(stringFromJNI);
        calcalculator();
    }

    public boolean onCreateOptionsMenu(Menu menu) {
        MenuInflater inflater = getMenuInflater();
        inflater.inflate(R.menu.main_menu,menu);
        return true;

    }

    @Override
    public boolean onOptionsItemSelected(@NonNull MenuItem item) {
        switch (item.getItemId()){

            case R.id.stand_mode:
                Toast.makeText(this,"Standard Calculator",Toast.LENGTH_SHORT).show();
                return true;
            case R.id.sci_mode:
                Intent intent1 = new Intent(this,SecondActivity.class);
                startActivity(intent1);
                Toast.makeText(this,"Switching to Scientific Calculator",Toast.LENGTH_SHORT).show();
                return true;
            default:return super.onOptionsItemSelected(item);

        }

    }

    private void configureSciMode() {
        Button scimode = findViewById(R.id.btnC);
        scimode.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(MainActivity.this,
                        SecondActivity.class));
            }
        });
    }

    //keypad handling


    public void clearAllEvent(View view) {
        et1.setText("0");
        isNewOperation = true;
    }

    public void clearLastChar(View view){
        String current_text = et1.getText().toString();
        if(current_text.length() == 1){
            et1.setText("0");
            isNewOperation = true;
        }
        else if (!isNewOperation){
            et1.setText(current_text.replace(current_text.substring(current_text.length() - 1),""));
        }
    }

    public boolean keyvalidate(String s,String buttonPressed){
        String [] operatorList = {"+", "-", "*", "/", ".", "%"};
        boolean isOperatorvalid;

        //check repeating operators
        String lastchar = s.substring(s.length() - 1);
        boolean prevOperator = Arrays.asList(operatorList).contains(lastchar);

        //HANDLE operator first
        if (isNewOperation == true ){
            if(buttonPressed.equals("*") || buttonPressed.equals("/") || buttonPressed.equals("%") || buttonPressed.equals(".")){
                prevOperator = true;
            }
        }

        //handle dot operator pressing twice in the same number
//        if (isOperator && buttonPressed == "."){
//            int valid = s.matches("(\\d*)(\\+")(\\)";
//        }

        if(prevOperator==true) isOperatorvalid = false;else isOperatorvalid = true;

        return  isOperatorvalid;
    }

    public void numberEvent(View view) {
        if (isNewOperation){
            et1.setText("");
        }
        isNewOperation = false;
        String number = et1.getText().toString();

        switch (view.getId()){
            case R.id.btn0:
                number += "0";
                break;
            case R.id.btn1:
                number += "1";
                break;
            case R.id.btn2:
                number += "2";
                break;
            case R.id.btn3:
                number += "3";
                break;
            case R.id.btn4:
                number += "4";
                break;
            case R.id.btn5:
                number += "5";
                break;
            case R.id.btn6:
                number += "6";
                break;
            case R.id.btn7:
                number += "7";
                break;
            case R.id.btn8:
                number += "8";
                break;
            case R.id.btn9:
                number += "9";
                break;
        }
        et1.setText(number);
    }

    public void operatorEvent(View view) {

        String number = et1.getText().toString();
        String keyPressed = "";

        switch (view.getId()){
            case R.id.btnpercent:
                keyPressed += "%";
                break;
            case R.id.btnAdd:
                keyPressed += "+";
                break;
            case R.id.btnSubtract:
                keyPressed += "-";
                break;
            case R.id.btnMultiply:
                keyPressed += "*";
                break;
            case R.id.btnDivide:
                keyPressed += "/";
                break;
            case R.id.btnDot:
                keyPressed += ".";
                break;
//            case R.id.btnPlusMinus:
//                keyPressed = "-";
//                break;
        }
        boolean iskeypressvalid = keyvalidate(number,keyPressed);

        if (iskeypressvalid){
            if (keyPressed == "-"){

            }else {
                number += keyPressed;
                et1.setText(number);
                isNewOperation = false;
            }
        }

    }



    //calculator functions
    public void calcalculator(){
        Button equalbtn = findViewById(R.id.btnEqual);
        equalbtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                sendInputToJNI();
                //getAnswer();
            }
        });
    }

    public void sendInputToJNI(){
        String s = et1.getText().toString();


        int x = nativeLib.InputToJNI(s,calMode);
        et1.setText(x);
    }

    public void getAnswer(){
        String out = nativeLib.outputFromJNI();

        TextView outtext = findViewById(R.id.editTextOutput);
        outtext.setText(out);
    }
}