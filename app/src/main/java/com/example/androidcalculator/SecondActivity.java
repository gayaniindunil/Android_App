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

public class SecondActivity extends AppCompatActivity {

    EditText et2;
    boolean isNewOperation2;
    private NativeLib nativeLib2;
    String calMode2;
    TextView outtext2;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_second);
//        configureBackButton();

        et2 = findViewById(R.id.editText2);
        isNewOperation2 = true;
        nativeLib2 = new NativeLib();
        calMode2 = "sci";
        outtext2= findViewById(R.id.editTextOutput2);

        calcalculator2();
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
                Intent intent2 = new Intent(SecondActivity.this,MainActivity.class);
                startActivity(intent2);
                Toast.makeText(this,"Switched to Standard Calculator",Toast.LENGTH_SHORT).show();
                return true;
            case R.id.sci_mode:
                Toast.makeText(this,"Scientific Calculator",Toast.LENGTH_SHORT).show();
                return true;
            default:return super.onOptionsItemSelected(item);
        }
    }

    public void clearAllEvent2(View view) {
        et2.setText("0");
        outtext2.setText("");
        isNewOperation2 = true;
    }

    public void clearLastChar2(View view){
        String current_text = et2.getText().toString();
        if(current_text.length() == 1){
            et2.setText("0");
            isNewOperation2 = true;
        }
        else if (!isNewOperation2){
            et2.setText(current_text.replace(current_text.substring(current_text.length() - 1),""));
        }
    }

    public boolean isOperatorPressValidate(String s,String buttonPressed){
        String [] operatorList = {"+", "-", "*", "/", ".", "%","^","sin","cos","tan","log","sqrt","(",")"};

        String [] operatorPossibleAfterDigit = {"+", "-", "*", "/", "%","^"};
        String [] operatorPossibleAfterOperator = {"sin", "cos", "tan", "log", "sqrt","(",")"};

        boolean isOperatorvalid = false;

        //check repeating operators
        String lastchar = s.substring(s.length() - 1);
        boolean lastcharisoperator = Arrays.asList(operatorList).contains(lastchar);

        if (lastcharisoperator){ // lastdigit is an operator
            if(lastchar == "("){ //{"sin", "cos", "tan", "log", "sqrt","(",")"} are possible after(
                if(buttonPressed.equals("sin")||buttonPressed.equals("cos")||buttonPressed.equals("tan")||
                        buttonPressed.equals("log")||buttonPressed.equals("sqrt")||buttonPressed.equals("(")){
                    isOperatorvalid = true;
                }
                else{
                    isOperatorvalid = false;
                }
            }
            else if (lastchar == ")"){
                if(buttonPressed.equals("+")||buttonPressed.equals("-")||buttonPressed.equals("*")||
                        buttonPressed.equals("/")||buttonPressed.equals("%")||buttonPressed.equals("^")){
                    isOperatorvalid = true;
                }
                else{
                    isOperatorvalid = false;
                }
            }
            else{ //{"+", "-", "*", "/", "%","^"} no repeat possible
                    isOperatorvalid = false;
                }
                isOperatorvalid = true;
            }
        else{ //lastchar is a number
            //lastchar is a number and "+", "-", "*", "/", "%","^" are possible after that
            boolean possibleOperatorAftrNum = buttonPressed.equals("+")||buttonPressed.equals("-")||buttonPressed.equals("*")||
                    buttonPressed.equals("/")||buttonPressed.equals("%")||buttonPressed.equals("^")||buttonPressed.equals(")");

            if(possibleOperatorAftrNum){
                isOperatorvalid = true;
            }else{ //lastchar is a number and "sin", "cos", "tan", "sqrt", "log",".", "(", ")" are  not possible after that
                isOperatorvalid = false;
            } //check . is possible
        }
        return isOperatorvalid;
    }

    public boolean DotOperaterValidate(String s){
        //handle dot operator pressing twice in the same number
//        if (isOperator && buttonPressed == "."){
//            int valid = s.matches("(\\d*)(\\+")(\\)";
//        }
        return false;
    }

    public boolean isFirstOperatorValid(String buttonPressed){

        boolean operatorValidate = true;

        if(buttonPressed.equals("*") || buttonPressed.equals("/") || buttonPressed.equals("%")|| buttonPressed.equals("^")||buttonPressed.equals(")")){
            return false;
        }
        else if(buttonPressed.equals("sin") || buttonPressed.equals("cos") || buttonPressed.equals("tan") ||
                buttonPressed.equals("(") || buttonPressed.equals("sqrt") || buttonPressed.equals("log")){
            return true;
        }
        else{
            // +,-,.
            return true;
        }

    }

    public void numberEvent2(View view) {
        if (isNewOperation2){
            et2.setText("");
        }
        isNewOperation2 = false;
        String number = et2.getText().toString();

        switch (view.getId()){
            case R.id.btn02:
                number += "0";
                break;
            case R.id.btn12:
                number += "1";
                break;
            case R.id.btn22:
                number += "2";
                break;
            case R.id.btn32:
                number += "3";
                break;
            case R.id.btn42:
                number += "4";
                break;
            case R.id.btn52:
                number += "5";
                break;
            case R.id.btn62:
                number += "6";
                break;
            case R.id.btn72:
                number += "7";
                break;
            case R.id.btn82:
                number += "8";
                break;
            case R.id.btn92:
                number += "9";
                break;
        }
        et2.setText(number);
    }

    public void handlePI(){
//        case R.id.pi:
//        keyPressed += "3.14";
//        break;
    }

    public void operatorEvent2(View view) {

        String number = et2.getText().toString();
        String keyPressed = "";

        switch (view.getId()){
            case R.id.btnAdd2:
                keyPressed += "+";
                break;
            case R.id.btnSubtract2:
                keyPressed += "-";
                break;
            case R.id.btnMultiply2:
                keyPressed += "*";
                break;
            case R.id.btnDivide2:
                keyPressed += "/";
                break;
            case R.id.btnpercent2:
                keyPressed += "%";
                break;
            case R.id.btnDot2:
                keyPressed += ".";
                break;
            case R.id.btnLeftParan:
                keyPressed += "(";
                break;
            case R.id.btnRgtParan:
                keyPressed += ")";
                break;
            case R.id.btnPowy:
                keyPressed += "^";
                break;
            case R.id.btnSin:
                keyPressed += "sin";
                break;
            case R.id.btnCos:
                keyPressed += "cos";
                break;
            case R.id.btnTan:
                keyPressed += "tan";
                break;
            case R.id.btnPow:
                keyPressed += "^";
                break;
            case R.id.btnSqurt:
                keyPressed += "sqrt";
                break;
            case R.id.btnLn:
                keyPressed += "log";
                break;
//            case R.id.btnPlusMinus:
//                keyPressed = "-";
//                break;
        }

        if (isNewOperation2){
            if(isFirstOperatorValid(keyPressed)){
                if(keyPressed.equals("+") || keyPressed.equals("-") || keyPressed.equals(".")){
                    number += keyPressed;
                }
                else if(!keyPressed.equals("(")){ //handle sin,cos,tan,sqrt,log
                    number = keyPressed +"(";
                }
                else if(keyPressed.equals("(")){ //handle sin,cos,tan,sqrt,log
                    number = "(";
                }
                isNewOperation2 = false;
            }
            else{// handle *,/,%,^,)
                isNewOperation2 = true;
            }
        }else{ //not a new operator
            boolean iskeypressvalid = isOperatorPressValidate(number,keyPressed);
            if(iskeypressvalid){
                number += keyPressed;
                if (keyPressed.equals("sin") || keyPressed.equals("cos") || keyPressed.equals("tan")||keyPressed.equals("sqrt") || keyPressed.equals("log")){
                    number += "(";
                }
            }
            isNewOperation2 = false;
        }
        et2.setText(number);
//
    }

    public void calcalculator2(){
        Button equalbtn2 = findViewById(R.id.btnEqual2);
        equalbtn2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                //sendInputToJNI();
                getAnswer2();
            }
        });
    }


    public void getAnswer2(){
        String s2 = et2.getText().toString();
        String out2 = nativeLib2.outputFromJNI(s2,calMode2);

        String text = outtext2.getText().toString();
        outtext2.setText(out2);
        isNewOperation2 = true;
    }
}