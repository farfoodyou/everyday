#include "rapidjson/document.h"     // rapidjson's DOM-style API
#include "rapidjson/prettywriter.h" // for stringify JSON
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

//using namespace rapidjson;

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

bool diff_json(rapidjson::Value& a,rapidjson::Value& b);
bool diff_value(rapidjson::Value& a,rapidjson::Value& b);

bool cout_node(rapidjson::Value& a);

int main(){

    std::string json1("{\"hello\":\"world\",\"t\":true,\"f\":false,\"n\":null,\"i\":123,\"pi\":3.1416,\"a\":[1,2,3,4]}");
    rapidjson::Document doc1;

    if (doc1.Parse(json1.c_str()).HasParseError())
        return 1;

    assert(doc1.HasMember("hello"));
    assert(doc1["hello"].IsString());
    printf("hello 1= %s\n", doc1["hello"].GetString());
    //printf("z 1  = %s\n", doc1["z"]["x"].GetString());

    std::string json("{\"hello\":\"wo3333rld\",\"t\":true,\"f\":false,\"n\":null,\"i\":123,\"pi\":3.1416,\"a\":[1,2,3,4],\"z\":{\"x\":\"xx\"}}");
    rapidjson::Document doc;

    if (doc.Parse(json.c_str()).HasParseError())
        return 1;

    assert(doc.HasMember("hello"));
    assert(doc["hello"].IsString());
    printf("hello = %s\n", doc["hello"].GetString());
    printf("z = %s\n", doc["z"]["x"].GetString());

    std::string json2("[\"xx\",\"eee\"]");
    rapidjson::Document doc2;

    if (doc2.Parse(json2.c_str()).HasParseError() || !doc2.IsArray()){
        printf("json2 err");
        return 1;
    }
    printf("doc2 1= %s\n", doc2[1].GetString());

    vector<int> vec;
    vec.push_back(10);
    vec.push_back(1);
    vec.push_back(13);
    sort(vec.begin(),vec.end());
    sort(vec.begin(),vec.end(),[](int& a, int& b)->bool{
        return b < a;
    });
    for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++){
        cout << *it<< endl;
    }

    // 开始 json 递归检查是否相同
    std::string diff_json_1("{\"hello\":\"wo3333rld\",\"t\":true,\"f\":false,\"n\":null,\"i\":123,\"pi\":3.1416,\"a\":[1,2,3,{\"s\":33},[33,34,54]],\"z\":{\"x\":\"xx\"}}");
    std::string diff_json_2("{\"hello\":\"wo3333rld\",\"t\":true,\"f\":false,\"n\":null,\"i\":123,\"pi\":3.1416,\"a\":[1,2,3,{\"s\":33},[33,34,54]],\"z\":{\"x\":\"xx\"}}");
    rapidjson::Document diff_doc_1;
    rapidjson::Document diff_doc_2;
    diff_doc_1.Parse(diff_json_1.c_str());
    diff_doc_2.Parse(diff_json_2.c_str());
    if(diff_doc_1 == diff_doc_2) {
        cout << " same json " << endl;
    } else {
        cout << " diff " << endl;
    }
    cout << " ================================= " << endl;
    diff_json(diff_doc_1, diff_doc_2);

    return 0;
}

static const char* kTypeNames[] = 
    { "Null", "False", "True", "Object", "Array", "String", "Number" };
bool diff_json(rapidjson::Value& base_object, rapidjson::Value& diff_object) {
    if (base_object.MemberCount() != diff_object.MemberCount()) {
        cout << " diff size " << endl;
    }

    for (rapidjson::Value::ConstMemberIterator itr = base_object.MemberBegin(),
        diff_itr = diff_object.MemberBegin();
        itr != base_object.MemberEnd() && diff_itr != diff_object.MemberEnd(); 
        ++itr, ++diff_itr)
    {
        std::string base_name(itr->name.GetString());
        std::string diff_name(diff_itr->name.GetString());
        if(base_name != diff_name || itr->value.GetType() != diff_itr->value.GetType()) {
            printf("Type of member %s is %s\n",itr->name.GetString(), kTypeNames[itr->value.GetType()]);
            printf("Type of member %s is %s\n",diff_itr->name.GetString(), kTypeNames[diff_itr->value.GetType()]);
        }
        //printf("Type of member %s is %s\n",itr->name.GetString());
        switch(itr->value.GetType()) {
            case rapidjson::Type::kObjectType: 
                diff_json(base_object[itr->name], diff_object[diff_itr->name]);
                break;
            case rapidjson::Type::kArrayType:
                if (itr->value.Size() == diff_itr->value.Size()) {
                    for (rapidjson::SizeType i = 0; i < itr->value.Size(); i++) {
                        cout << i << " value= " << endl;
                        diff_value(itr->value[i], diff_itr->value[i]);
                    }
                } else {
                    cout << "array size not equal" << endl;
                }
                break;
            case rapidjson::Type::kNullType: 
            case rapidjson::Type::kFalseType: 
            case rapidjson::Type::kTrueType: 

                break;
            case rapidjson::Type::kNumberType: 
                double base_number;
                double diff_number;
                double delta;
                base_number = base_object[itr->name].GetDouble();
                diff_number = diff_object[diff_itr->name].GetDouble();
                delta = base_number - diff_number;
                if (delta > 0.00001 || delta < -0.00001) {
                    return false;
                }
                break;
            case rapidjson::Type::kStringType: 
                cout << base_object[itr->name].GetString() << "  " << diff_object[diff_itr->name].GetString() << endl;
                break;
        }
    }
    return true;
}
bool diff_value(rapidjson::Value& base_value, rapidjson::Value& diff_value) {

    if(base_value.GetType() != diff_value.GetType()) {
        printf("Type of member %d \n",base_value.GetType());
        printf("Type of member %d \n",diff_value.GetType());
        return false;
    }
    printf("Type of member %d \n",base_value.GetType());
    switch(base_value.GetType()) {
        case rapidjson::Type::kObjectType: 
            //diff_json(base_value, diff_value);
            break;
        case rapidjson::Type::kArrayType:
            if (base_value.Size() == diff_value.Size()) {
                for (rapidjson::Value::ConstValueIterator itr = base_value.Begin(); itr != base_value.End(); ++itr){
                    //cout <<  << " value ele \n";
                    //diff_value(*itr, *itr);
                }

                for (rapidjson::SizeType i = 0; i < base_value.Size(); i++) {
                    //printf("value  Type of member is %s\n",kTypeNames[base_value[i].value.GetType()]);
                    //diff_value(base_value[i], diff_value[i]);
                }
            } else {
                cout << "array size not equal" << endl;
            }
            break;
        case rapidjson::Type::kNullType: 
        case rapidjson::Type::kFalseType: 
        case rapidjson::Type::kTrueType: 
            break;
        case rapidjson::Type::kNumberType: 
            double base_number;
            double diff_number;
            double delta;
            base_number = base_value.GetDouble();
            diff_number = diff_value.GetDouble();
            delta = base_number - diff_number;
            if (delta > 0.00001 || delta < -0.00001) {
                return false;
            }
            break;
        case rapidjson::Type::kStringType: 
            cout << base_value.GetString() << "  "  << diff_value.GetString() << endl;
            break;
    }
    
}

bool cout_node(rapidjson::Value& base_value) {
    cout << " ------------ " << endl;
    switch(base_value.GetType()) {
        case rapidjson::Type::kObjectType: 
            cout << " o " << endl;
            //diff_json(base_value, diff_value);
            break;
        case rapidjson::Type::kArrayType:
            cout <<  base_value.Size()  << " size array size" << endl;
            break;
        case rapidjson::Type::kNullType: 
            cout << " null " << endl;
            break;
        case rapidjson::Type::kFalseType: 
            cout << " False " << endl;
            break;
        case rapidjson::Type::kTrueType: 
            cout << " True " << endl;
            break;
        case rapidjson::Type::kNumberType: 
            double base_number;
            double diff_number;
            double delta;
            base_number = base_value.GetDouble();
            cout << " Number: "<< base_number << endl;
            break;
        case rapidjson::Type::kStringType: 
            cout << " String: "<< base_value.GetString()  << endl;
            break;
    }
}
// 通用 json diff 工具
    //sort(base_document.MemberBegin(), base_document.MemberEnd(), [&](Value& a, Value& b)->bool{
    //    return a.name.GetString() < b.name.GetString();
    //});
    //sort(base_document.MemberBegin(), base_document.MemberEnd());
