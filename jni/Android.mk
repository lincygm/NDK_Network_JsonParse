
LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)  
LOCAL_MODULE := curl  
LOCAL_SRC_FILES := libs/$(TARGET_ARCH_ABI)/libcurl.so
include $(PREBUILT_SHARED_LIBRARY) 


##########编译jsoncpp###############
include $(CLEAR_VARS)
OPENCV_CAMERA_MODULES:=off
LOCAL_MODULE    := NDK_01
#LOCAL_SRC_FILES := jsoncpp/jniCoreMethod.cpp  \
			 
LOCAL_LDLIBS += -L$(SYSROOT)/usr/lib -llog
LOCAL_ALLOW_UNDEFINED_SYMBOLS := true
 
APP_PLATFORM := android-19  
include $(BUILD_SHARED_LIBRARY)





##########编译jsoncpp###############


include $(CLEAR_VARS)
LOCAL_C_INCLUDES := $(LOCAL_PATH)/include
LOCAL_MODULE := curlTest
LOCAL_SRC_FILES := src/DownloadModule.cpp \
	src/HttpPostModule.cpp \
	src/Main.cpp \
	src/JNIUtil.cpp \
	src/jniCoreMethod \
	src/jsoncpp.cpp 
	
LOCAL_SHARED_LIBRARIES := curl

LOCAL_LDLIBS := -llog
include $(BUILD_SHARED_LIBRARY)



#将编译好的文件cp到libs目录中

PRODUCT_COPY_FILES += $(LOCAL_PATH)/libs/:../



