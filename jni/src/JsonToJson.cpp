#include "jsontojson.h"

 JsonHandle::JsonHandle(){
}

 void   JsonHandle::jsonStringtransform(const char* data){
        Json::Reader reader;
        Json::Value root;
        if(reader.parse((string)data,root)){
                string name = root["name"].asString();
                string gender = root["gender"].asString();
                LOGE(  "Get Param:  %s  From Java",gender.c_str());
                 LOGE( "Get Param:  %s  From Java", name.c_str());
                //std::cout<<name;
                //std::cout<<gender<<endl;
                 map<string,string> mm ;
                 mm.insert(pair<string,string>( name.c_str(),gender.c_str()));
        }
     // return mm;
}
 JsonHandle::~JsonHandle(){

}



