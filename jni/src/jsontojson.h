#ifndef JSON_H
#define JSON_H
#include <android/log.h>
#include <iostream>
#include <string>
#include <jni.h>
#include "../jsoncpp/json.h"
#include "jsoncpp.cpp"
#include <cstring>
#include "JNIUtil.h"
#include "Main.h"
using namespace std;

class JsonHandle{

public:
    JsonHandle();
    ~JsonHandle();
    void   jsonStringtransform(const char* data);

};
#endif

