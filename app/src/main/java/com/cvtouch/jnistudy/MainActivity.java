package com.cvtouch.jnistudy;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;

import com.cvtouch.jnilib.Callbacks;

public class MainActivity extends AppCompatActivity {
	
	private Callbacks mCallbacks = new Callbacks();

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		
		mCallbacks.nativeMethod(0);
	}
}
