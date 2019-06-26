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

bool diff_json(const rapidjson::Value& a,const rapidjson::Value& b);
bool diff_value(const rapidjson::Value& a,const rapidjson::Value& b);

bool cout_node(const rapidjson::Value& a);

int main(){

    // 开始 json 递归检查是否相同
    std::string diff_json_1("{\"hello\":\"wo3333rld\",\"t\":true,\"f\":false,\"n\":null,\"i\":123,\"pi\":-3.3,\"a\":[1,2,3,{\"s\":33},[33,34,54]],\"z\":{\"x\":\"xx\"}}");
    std::string diff_json_2("{\"hello\":\"wo3333rld\",\"t\":true,\"f\":false,\"n\":null,\"i\":123,\"pi\":-3,\"a\":[1,2,3,{\"s\":33},[33,34,54]],\"z\":{\"x\":\"xx\"}}");
    rapidjson::Document diff_doc_1;
    rapidjson::Document diff_doc_2;
    diff_doc_1.Parse(diff_json_1.c_str());
    diff_doc_2.Parse(diff_json_2.c_str());
    if(diff_doc_1 == diff_doc_2) {
        cout << " same json " << endl;
    } else {
        cout << " diff " << endl;
    }
    cout << " pi is " << diff_doc_1["pi"].GetDouble() << endl;
    cout << " ================================= " << endl;
    diff_json(diff_doc_1, diff_doc_2);

    return 0;
}

static const char* kTypeNames[] = 
    { "Null", "False", "True", "Object", "Array", "String", "Number" };
bool diff_json(const rapidjson::Value& base_object,const  rapidjson::Value& diff_object) {
    if (!base_object.IsObject()) {
        cout << " " << endl;
        cout_node(base_object);
        cout_node(base_object);
        return false;
    }

    if (base_object.MemberCount() != diff_object.MemberCount()) {
        cout << " diff size " << endl;
    }

    for (rapidjson::Value::ConstMemberIterator itr = base_object.MemberBegin(),
        diff_itr = diff_object.MemberBegin();
        itr != base_object.MemberEnd() && diff_itr != diff_object.MemberEnd(); 
        ++itr, ++diff_itr)
    {
        printf("Type of member %s is %s\n",itr->name.GetString(), kTypeNames[itr->value.GetType()]);
        printf("Type of member %s is %s\n",diff_itr->name.GetString(), kTypeNames[diff_itr->value.GetType()]);
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
                        //cout_node(itr->value[i]);
                        diff_json(itr->value[i], diff_itr->value[i]);
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
bool diff_value(const rapidjson::Value& base_value,const rapidjson::Value& diff_value) {

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

bool cout_node(const rapidjson::Value& base_value) {
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
// 通用 json diff 库
    //sort(base_document.MemberBegin(), base_document.MemberEnd(), [&](Value& a, Value& b)->bool{
    //    return a.name.GetString() < b.name.GetString();
    //});
    //sort(base_document.MemberBegin(), base_document.MemberEnd());

/*
 * 本来打算直接用 json 作为对比两棵树
 * 但是还是用 proto 来进行, 可能速度上差不多
 * 哭了.... 哪天熬夜写了啥, 在于自己坑自己啊.
 * 拿不出手, 拿不出手, 一年了, 结果还是这样.
 * 
 */

/* 
 * 正确性, 完整性, 鲁棒性的高质量代码.
 * 自信的原点, 现在我已经掌握了更加先进的学习方法了.
 * 题海战术? 例子学习, 大量训练. 对抗遗忘? 顺应遗忘, 强化记忆
 * 
 **/
