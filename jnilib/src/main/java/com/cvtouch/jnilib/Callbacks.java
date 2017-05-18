package com.cvtouch.jnilib;

import android.util.Log;

/**
 * Created by debbie on 2017/5/16.
 */

public class Callbacks {
	
	static {
		System.loadLibrary("jnilib");
	}
	
	public native void nativeMethod(int depth);
	
	private void callback(int depth) {
		if(depth < 5) {
			Log.d("jni", "In Java, depth = " + depth + ", about to enter C");
			nativeMethod(depth + 1);
			Log.d("jni", "In Java, depth = " + depth + ", back from C");
		} else {
			Log.d("jni", "In Java, depth = " + depth + ", limit exceeded");
		}
	}
	
	private static void callback2() {
		Log.d("jni", "In Java, from native, call static method");
	}
}
