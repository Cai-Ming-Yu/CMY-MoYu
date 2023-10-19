LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES = MoYu.cpp

LOCAL_MODULE := MoYu

LOCAL_MODULE_FILENAME := MoYu

LOCAL_LDFLAGS := -static -fPIC -O3 -Wl,--strip-all -pipe

include $(BUILD_EXECUTABLE)