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
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    EditText et1;
    boolean isNewOperation = true;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        et1 = findViewById(R.id.editText);
        configureSciMode();
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
                Toast.makeText(this,"Scientific Calculator",Toast.LENGTH_SHORT).show();
                return true;
            default:return super.onOptionsItemSelected(item);

        }

    }

    private void configureSciMode() {
        Button scimode = findViewById(R.id.btnSciMode);
        scimode.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(MainActivity.this,
                        SecondActivity.class));
            }
        });
    }

    public void clearEvent(View view) {
        et1.setText("0");
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
            case R.id.btnDot:
                number += ".";
                break;
            case R.id.btnPlusMinus:
                number = "-" + number;
                break;
        }
        et1.setText(number);
    }

    public void operatorEvent(View view) {
        String number = et1.getText().toString();
        isNewOperation = false;
        switch (view.getId()){
            case R.id.btnpercent:
                number += "%";
                break;
            case R.id.btnAdd:
                number += "+";
                break;
            case R.id.btnSubtract:
                number += "-";
                break;
            case R.id.btnMultiply:
                number += "*";
                break;
            case R.id.btnDivide:
                number += "/";
                break;

        }
        et1.setText(number);
    }
}