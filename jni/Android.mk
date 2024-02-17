LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES = MoYu.cpp

LOCAL_MODULE := MoYu

LOCAL_MODULE_FILENAME := MoYu

LOCAL_LDFLAGS := -static -Wl,--strip-all -O3 -fPIC -pipe -g0 -flto=thin

include $(BUILD_EXECUTABLE)