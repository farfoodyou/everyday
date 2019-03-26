#include "rapidjson/document.h"     // rapidjson's DOM-style API
#include "rapidjson/prettywriter.h" // for stringify JSON
#include <cstdio>
#include <string>
#include <iostream>

using namespace rapidjson;
using namespace std;

class mybase {
public:
    int id;
    int hi(){
        return this->id;
    };
    mybase(){
        id = 123;
    };
};

int main(){
    mybase* a = new mybase();
    a->hi();
    printf("hi: %d\n", a->hi());

    std::string json1("{\"hello\":\"world\",\"t\":true,\"f\":false,\"n\":null,\"i\":123,\"pi\":3.1416,\"a\":[1,2,3,4]}");
    Document doc1;

    if (doc1.Parse(json1.c_str()).HasParseError())
        return 1;

    assert(doc1.HasMember("hello"));
    assert(doc1["hello"].IsString());
    printf("hello 1= %s\n", doc1["hello"].GetString());
    //printf("z 1  = %s\n", doc1["z"]["x"].GetString());

    std::string json("{\"hello\":\"wo3333rld\",\"t\":true,\"f\":false,\"n\":null,\"i\":123,\"pi\":3.1416,\"a\":[1,2,3,4],\"z\":{\"x\":\"xx\"}}");
    Document doc;

    if (doc.Parse(json.c_str()).HasParseError())
        return 1;

    assert(doc.HasMember("hello"));
    assert(doc["hello"].IsString());
    printf("hello = %s\n", doc["hello"].GetString());
    printf("z = %s\n", doc["z"]["x"].GetString());

    std::string json2("[\"xx\",\"eee\"]");
    Document doc2;

    if (doc2.Parse(json2.c_str()).HasParseError() || !doc2.IsArray()){
        printf("json2 err");
        return 1;
    }
    printf("doc2 1= %s\n", doc2[1].GetString());

    return 0;
}