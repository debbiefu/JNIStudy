//
// Created by Debbie on 2017/5/16.
//
#include "com_cvtouch_jnilib_Callbacks.h"

static JavaVM *g_vm = NULL;

void callJavaStaticMethod(JNIEnv *env, const char* className, const char* methodName, const char* methodDescribe) {
	jclass cls = env->FindClass(className);
    if(NULL == cls) {
    	ALOGI("Find class fail");
        return;
    }
    jmethodID mid = env->GetStaticMethodID(cls, methodName, methodDescribe);
    if(NULL == mid) {
        ALOGI("GetStaticMethodID fail");
        return;
    }
    env->CallStaticVoidMethod(cls, mid);
}

void callJavaStaticMethodWithoutENVParam(const char* className, const char* methodName, const char* methodDescribe) {
	JNIEnv *env;
        
    int getEnvStat = g_vm->GetEnv(&env, JNI_VERSION_1_6);
    if (getEnvStat == JNI_EDETACHED) {
        ALOGI("GetEnv: not attached");
        if (g_vm->AttachCurrentThread(&env, NULL) != 0) {
	        ALOGI("Failed to attach");
        }
    } else if (getEnvStat == JNI_OK) {
        //
    } else if (getEnvStat == JNI_EVERSION) {
        ALOGI("GetEnv: version not supported");
    }
    
    callJavaStaticMethod(env, className, methodName, methodDescribe);
    
    if (env->ExceptionCheck()) {
        env->ExceptionDescribe();
    }
}

JNIEXPORT void JNICALL Java_com_cvtouch_jnilib_Callbacks_nativeMethod(JNIEnv *env, jobject obj, jint depth) 
{
	jclass cls = env->GetObjectClass(obj);
	jmethodID mid = env->GetMethodID(cls, "callback", "(I)V");
	if(NULL == mid) {
		ALOGI("GetMethodID fail");
		return;
	}
	ALOGI("In C, depth = %d, about to enter Java\n", depth);
	env->CallVoidMethod(obj, mid, depth);
	ALOGI("In C, depth = %d, back from Java\n", depth);
	
	// Call static java method with env
	//callJavaStaticMethod(env, "com/cvtouch/jnilib/Callbacks", "callback2", "()V");
	
	// Call static java method without env
	callJavaStaticMethodWithoutENVParam("com/cvtouch/jnilib/Callbacks", "callback2", "()V");
}

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved)
{
	g_vm = vm;
	return JNI_VERSION_1_6;
}



