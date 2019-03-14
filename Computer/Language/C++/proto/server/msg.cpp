#include "msg.pb.h"
#include <stdio.h>

int main(){
    EchoMsg emsg;
    emsg.set_msg("hi, my baby");
    int len = emsg.ByteSize();
    char * buf = new char[len];
    emsg.SerializeToArray(buf, len);
    puts(buf);
    //EchoMsg emsg2;
    //emsg2.ParseFromArray(buf,len);
    //std::cout<< emsg2.msg() <<std::endl;
    printf("over\n");
}

/*
c++ msg.cpp msg.pb.h msg.pb.cc -o test -I/usr/local/protobuf/include -L/usr/local/protobuf/lib -lprotobuf -pthread

g++ msg.cpp msg.pb.h msg.pb.cc  -o msg_test -std=c++11 -I /usr/local/include -L /usr/local/lib -lprotobuf -pthread

2019-03-11 14:37:45 昨天那个是因为没有使用c++11导致的.
我靠...好吧, 果然, 对 c++ 的编译了解还不够透彻啊.

*/