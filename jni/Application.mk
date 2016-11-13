#APP_PLATFORM = android-8
APP_ABI := armeabi-v7a armeabi x86
APP_STL := gnustl_static
APP_STL := stlport_static
#APP_CPPFLAGS +=-std=c++11
APP_CPPFLAGS := -fexceptions -frtti #允许异常功能，及运行时类型识别  
APP_CPPFLAGS +=-fpermissive
