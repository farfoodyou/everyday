#include "msg.pb.h"
#include <iostream>
#include <cstdio>

int main(){
    EchoMsg emsg;
    emsg.set_msg("hi, my baby");
    //int len = emsg.ByteSize();
    //char * buf = new char[len];
   //emsg.SerializeToArray(buf, len);
    //puts(buf);
    //EchoMsg emsg2;
    //emsg2.ParseFromArray(buf,len);
    //std::cout<< emsg2.msg() <<std::endl;
    printf("over\n");
}

// c++ -o a main.cpp msg.pb.h msg.pb.cc -I/usr/local/protobuf/include -L/usr/local/protobuf/lib -lprotobuf -pthread
/*

g++ -o mm main.cpp msg.pb.h msg.pb.cc -I /usr/local/include -L /usr/local/lib -lprotobuf

*/