#!/usr/bin/python
# -*- coding: UTF-8 -*-
import json

'''
作者:farfood@qq.com
日期:20190416
说明: 这个文件用来转化 proto ShortDebugString 产生的结果为 json string
请直接调用solve函数
注意事项1: 如果有枚举, 可能需要修改 Edict 字典
注意事项2: 如果如果确定某一key是list,在solve中修改res即可

基本原理: 
1. 读取 str 中的 key { substr } 和 key: value 两种,如果 key 已存在,转化成列表. 
2. 递归地转化 substr
'''

str = 'rec_input { rec_type: "POS_PERSONAL_ANDROID" rec_param { rec_id: "POS_PERSONAL_ANDROID" rec_num: 7 } } history_disp { type: "bsp_history_7d" } history_disp { type: "bsp_history_1d" } rec_ctx { system_type: "android" system_version: "9" length: 2137 width: 1080 province: "" city: "" shoubai_version: "11.7.0.10" shoubai_type: "" device_model: "JSN-AL00a" device_vendor: "HUAWEI" user_ip: "10.159.36.160" }'

# 对全局变量str 进行转化, 转化范围是 [begin,end)
def toJson(begin,end):
    p = begin
    lastp = begin
    keyst = {}
    while(p < end):
        if (str[p]==':'):
            key = str[lastp:p]
            key = key.strip(' ')
            lastp = p+1
            p+=2
            while(str[p]!=' ' and p < end):
                p+=1
            o = toJson(lastp,p)
            lastp = p+1
            if(key in keyst):
                if(type(keyst[key]).__name__ != 'list'):
                    tmp = keyst[key]
                    keyst[key] = []
                    keyst[key].append(tmp)
                keyst[key].append(o)
            else:
                keyst[key] = o
        elif (str[p]=='{'):
            key = str[lastp:p]
            key = key.strip(' ')
            st=[]
            st.append('{')
            lastp = p+1
            p+=1
            z = 0
            while(len(st)>0 and p < end):
                if(str[p] == '{'):
                    st.append('{')
                elif(str[p] == '}'):
                    st.pop()
                p+=1
            p-=1 
            o = toJson(lastp,p)
            lastp = p+2
            p+=2
            if(key in keyst):
                if(type(keyst[key]).__name__ != 'list'):
                    tmp = keyst[key]
                    keyst[key] = []
                    keyst[key].append(tmp)
                keyst[key].append(o)
            else:
                keyst[key] = o
        else:
            p+=1
    if(len(keyst)==0):
        return str[begin:end].strip(' ')
    return keyst
# 如果是枚举可能需要修改这个字典
Edict = {
    'GAME_PAGE_TYPE_HOME':0,
    'GAME_PAGE_TYPE_MORE':1,
    'RAC_RANK_TYPE_COMMON':0, 
    'RAC_DISPLAY_TYPE_GAME_BIG_PHOTO':1,
    'RAC_DISPLAY_TYPE_GAME_SMALL_PHOTO':2,
    'RAC_DISPLAY_TYPE_COMMON':0,
    'RAC_RANK_TYPE_FOLLOW':1,
    'RAC_RANK_TYPE_RANKING':2
}

def Travese(json):
    global Edict
    #print(Edict)
    if(type(json).__name__=='dict'):
        for item in json:
            if(type(json[item]).__name__=='dict' or type(json[item]).__name__=='list'):
                Travese(json[item])
            elif('"' in json[item]):
                json[item] = json[item].strip('"')
            elif(json[item].isdigit()):
                json[item] = int(json[item])
            elif(json[item] in Edict):
                #print(item,json[item])
                json[item] = Edict[json[item]]
    else:
        for item,v in enumerate(json):
            if(type(json[item]).__name__=='dict' or type(json[item]).__name__=='list'):
                Travese(json[item])
            elif('"' in json[item]):
                json[item] = json[item].strip('"')
            elif(json[item].isdigit()):
                json[item] = int(json[item])
            elif(json[item] in Edict):
                #print(item,json[item])
                json[item] = Edict[json[item]]
def solve(input_str):
    global str
    str = input_str + '  '
    res = toJson(0,len(str))
    Travese(res)
    output_str = json.dumps(res)
    print(output_str)
    return output_str

z='z { x: 3 } z { x:4 } x: 34'
solve(z)
