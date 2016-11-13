#include "../jsoncpp/com_hyy_jni_MainActivity.h"
#include "jsontojson.h"

/*
 * Class:     com_genepoint_jni_JniActivity
 * Method:    getStringFromNative
 * Signature: ()Ljava/lang/String;
 */
jstring Java_com_example_curltest_MainActivity_getStringFromJNI
  (JNIEnv *env, jobject thiz){
    return env->NewStringUTF("Hello From JNI!");
}

jstring Java_com_example_curltest_MainActivity_tranformJson
  (JNIEnv *env, jobject thiz, jstring code){
        // transfor data from android
       // const char *str_data = env->GetStringUTFChars(code,0);
                //string tmp = jsonStringtransform(str_data);
                return env->NewStringUTF("tmp.c_str()");
}
