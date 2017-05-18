LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := jnilib

LOCAL_SRC_FILES := com_cvtouch_jnilib_Callbacks.cpp

LOCAL_C_INCLUDES := ./

LOCAL_LDLIBS := -llog

include $(BUILD_SHARED_LIBRARY)