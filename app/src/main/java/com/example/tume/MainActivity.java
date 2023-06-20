package com.example.tume;

import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

import com.renjiayi.tume.databinding.ActivityMainBinding;


public class MainActivity extends AppCompatActivity {

    // Used to load the 'jni' library on application startup.
    static {
        System.loadLibrary("jni");
    }

    private ActivityMainBinding binding;

    private String name = "1111";

    private static int age = 10;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        // Example of a call to a native method
        TextView tv = binding.sampleText;
        /*tv.setText(stringFromJNI());*/
        changeName();
        tv.setText(name);
        changeInt();
        tv.setText(String.valueOf(age));
        int a = callAdd();
        Log.d("renjiayi", "onCreate: " + a);
    }

    public native void changeName();

    public static native void changeInt();

    public int add(int num1, int num2) {
        return num1 + num2;
    }

    /**
     * A native method that is implemented by the 'jni' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();


    public native int callAdd();
}