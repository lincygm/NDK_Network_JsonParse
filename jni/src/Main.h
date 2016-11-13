#ifndef _Included_com_example_Main
#define _Included_com_example_Main



#ifdef __cplusplus
extern "C" {
#endif

void Java_com_example_curltest_MainActivity_TestHttpPost(JNIEnv* env,  jobject obj);

void* DownloadApps(const char* url ,const char* appName);

char* ReadFile(const char* filename);

void Java_com_example_curltest_MainActivity_Init(JNIEnv* env, jobject obj);

void Java_com_example_curltest_MainActivity_Cleanup(JNIEnv* env, jobject obj);

void Java_com_example_curltest_MainActivity_SendSMS(JNIEnv *env,jclass thizz,jobject thiz,jobject savedInstanceState);

void Java_com_example_curltest_MainActivity_TestDownload(JNIEnv* env,jobject obj);

#ifdef __cplusplus
}
#endif
#endif
