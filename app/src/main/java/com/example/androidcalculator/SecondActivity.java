package com.example.androidcalculator;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

public class SecondActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_second);
        configureBackButton();
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

    public void configureBackButton() {
        Button bckBtn = findViewById(R.id.btnNormMode);
        bckBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                finish();
            }
        });
    }
}