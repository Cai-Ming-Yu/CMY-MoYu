APP_MODULES := MoYu
ARCH := 64 # 32 or 64
ifeq ($(ARCH), 64)
    APP_PLATFORM := android-19
    APP_ABI := arm64-v8a x86_64
endif
ifeq ($(ARCH), 32)
    APP_PLATFORM := android-21
    APP_ABI := armeabi-v7a x86
endif
APP_OPTIM := release
APP_STL := c++_static