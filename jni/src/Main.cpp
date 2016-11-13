#include <jni.h>
#include "DownloadModule.h"
#include "HttpPostModule.h"
#include "JNIUtil.h"
#include <pthread.h>
#include "Main.h"
#include "jsontojson.h"
#include "../jsoncpp/com_hyy_jni_MainActivity.h"
#include<unistd.h>
extern "C"{

typedef struct {
   const  char url[] ;
   const  char appName[];
}DownloadUrl[10];

jobject g_objAc = NULL;
FILE   *stream;

void Java_com_example_curltest_MainActivity_TestDownload(JNIEnv* env,
                jobject obj)
{


       // DownloadApps("http://sdfsdf.sydzxl.com/xiezai.txt","xiazai.txt");
        int result =  access("/mnt/sdcard/Download/xiazai.txt", 4);//  file is exist
        char *path = "/mnt/sdcard/Download/xiazai.txt";
        char *strings = ReadFile(path);
        LOGE("json--- \n %d   %s",result,strings);
        //string data =(string)strings;
        //JsonHandle jsonHandle;
        //jsonHandle. jsonStringtransform(strings);

        //int NUM_THREADS =1;
       // pthread_t tids[NUM_THREADS]; //线程id
         //   for( int i = 0; i < NUM_THREADS; ++i )
         //   {
                //int ret = pthread_create( &tids[i], NULL, DownloadApps, NULL ); //参数：创建的线程id，线程参数，线程运行函数的起始地址，运行函数的参数
                //if( ret != 0 ) //创建线程成功返回0
                //{
                  //  cout << "pthread_create error:error_code=" << ret << endl;
                //}
         //   }
            //pthread_exit( NULL ); //等待各个线程退出后，进程才结束，否则进程强制结束，线程处于未终止的状态
}



char* ReadFile(const char*  filename){
   char *buffer = NULL;
   int string_size,read_size;
   FILE *handler = fopen(filename,"r");

   if (handler){
       //seek the last byte of the file
       fseek(handler,0,SEEK_END);
       //offset from the first to the last byte, or in other words, filesize
       string_size = ftell (handler);
       //go back to the start of the file
       rewind(handler);

       //allocate a string that can hold it all
       buffer = (char*) malloc (sizeof(char) * (string_size + 1) );
       //read it all in one operation
       read_size = fread(buffer,sizeof(char),string_size,handler);
       //fread doesnt set it so put a \0 in the last position
       //and buffer is now officialy a string
       buffer[string_size+1] = '\0';

       if (string_size != read_size) {
           //something went wrong, throw away the memory and set
           //the buffer to NULL
           free(buffer);
           buffer = NULL;
        }
    }else{
            LOGE("gm cannot open file !");
   }
    return buffer;
}



void* DownloadApps(const char* url ,const char* appName)
{
    DownLoadModule download;
    //const char* url ="http://sdfsdf.sydzxl.com/xiezai.txt";
    int nRet = download.DownLoad(url, "/sdcard/Download", appName);
    if (nRet == 0){
            LOGI("download success!");
   } else{
            LOGE("download error code:%d", nRet);
    }
}
size_t PostDispose(char *buffer, size_t size, size_t nmemb, void *userdata)
{
        JNIUtil util;
        jobject jdata = util.String2Jstring(buffer);
        JNIEnv* env = util.GetJNIEnv();
        jclass cMainActivity = env->GetObjectClass(g_objAc);
        jmethodID methodPostDispose = env->GetMethodID(cMainActivity, "postDispose",
                        "(Ljava/lang/String;)V");
        env->CallVoidMethod(g_objAc, methodPostDispose, jdata);
        return nmemb;
}
void Java_com_example_curltest_MainActivity_TestHttpPost(JNIEnv* env,
                jobject obj)
{
        HttpPostModule post;
        post.SetTimeOut(60);
        post.SetHttpHead("Content-Type:application/json;charset=UTF-8");
        post.SetWriteFunction(PostDispose);
        post.SetURL("http://api.map.baidu.com/place/v2/suggestion?query=tiananmen&region=131&output=json&ak=fTF5Wt01MNLs7ci9G9G6X76d");
        int nRet = post.SendPostRequest();
        if (nRet == 0)
                LOGI("post success!");
        else
                LOGE("post error code:%d", nRet);
}
void Java_com_example_curltest_MainActivity_Init(JNIEnv* env, jobject obj)
{
        HttpPostModule::Init();
        JavaVM* vm;
        env->GetJavaVM(&vm);
        JNIUtil::Init(env);
        g_objAc = env->NewGlobalRef(obj);
}
void Java_com_example_curltest_MainActivity_Cleanup(JNIEnv* env, jobject obj)
{
        HttpPostModule::Cleanup();
        env->DeleteGlobalRef(g_objAc);
        g_objAc = NULL;
        JNIUtil::CleanUp(env);
}

void Java_com_example_curltest_MainActivity_SendSMS(JNIEnv *env,jclass thizz,
                                                    jobject thiz,jobject savedInstanceState){

    JNIUtil ::SendSMS(env);
}

}

