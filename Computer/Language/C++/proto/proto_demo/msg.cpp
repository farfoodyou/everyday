#include "msg.pb.h"
#include <cstdio>
#include <iostream>
#include <cstring>
#include <google/protobuf/util/json_util.h>

int main(){
    EchoMsg emsg;
    emsg.set_msg("hi, my baby");
    int len = emsg.ByteSize();
    char * buf = new char[len];
    emsg.SerializeToArray(buf, len);
    puts(buf);
    printf("over\n");

    // 序列化 和 反序列化
    std::string serialize_str;
    emsg.SerializeToString(&serialize_str);

    EchoMsg emsg_2;
    emsg_2.ParseFromString(serialize_str);
    std::cout << emsg_2.msg() << std::endl;
    std::cout << emsg_2.DebugString() << std::endl;

    // 添加 repeated 的值.
    emsg_2.add_tuple("tuple1");
    emsg_2.add_tuple("tuple2");

    Body body;
    body.add_tuple("tuple2");
    Body* body_ptr = emsg_2.add_body();
    body_ptr->add_tuple("body tuple1");
    body_ptr->add_tuple("body tuple2");
    std::cout << "=====[ DebugString ]======" << std::endl;
    std::cout << emsg_2.DebugString() << std::endl;

    // proto to json
    std::string json_str;
    google::protobuf::util::MessageToJsonString(emsg_2, &json_str);
    std::cout << json_str << std::endl;

    // json to proto
    EchoMsg emsg_from_json;
    std::cout << "=====[ emsg_from_json ]======" << std::endl;
    google::protobuf::util::JsonStringToMessage(json_str, &emsg_from_json);
    std::cout << emsg_from_json.DebugString() << std::endl;

    // proto to binary
    std::string binary_str;
    google::protobuf::util::Mess(emsg_2, &binary_str);
    std::cout << binary_str << std::endl;
    return 0;
}

/*
c++ msg.cpp msg.pb.h msg.pb.cc -o test -I/usr/local/protobuf/include -L/usr/local/protobuf/lib -lprotobuf -pthread

g++ msg.cpp msg.pb.h msg.pb.cc  -o msg_test -std=c++11 -I /usr/local/include -L /usr/local/lib -lprotobuf -pthread

2019-03-11 14:37:45 昨天那个是因为没有使用c++11导致的.
我靠...好吧, 果然, 对 c++ 的编译了解还不够透彻啊.

2019-07-02 21:31:22 这里居然没有关于如何转化 proto 到 c++文件的 相关记录
protoc -I=$SRC_DIR --cpp_out=$DST_DIR $SRC_DIR/game.proto
protoc -I=./ --cpp_out=./ ./msg.proto

2019-07-05 23:04:38
1. 将 proto 编译成c++代码
2. 编译main文件是引入对应的proto文件
*/
