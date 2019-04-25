#!/usr/bin/python
# -*- coding: UTF-8 -*-
import json

'''
作者:
日期:20190416
说明: 这个文件用来转化 proto ShortDebugString 产生的结果为 json string
'''

str = 'rec_input { rec_type: "POS_PERSONAL_ANDROID" rec_param { rec_id: "POS_PERSONAL_ANDROID" rec_num: 7 } } history_disp { type: "bsp_history_7d" } history_disp { type: "bsp_history_1d" } rec_ctx { system_type: "android" system_version: "9" length: 2137 width: 1080 province: "" city: "" shoubai_version: "11.7.0.10" shoubai_type: "" device_model: "JSN-AL00a" device_vendor: "HUAWEI" user_ip: "10.159.36.160" }'

# [begin,end)
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
    str = input_str
    res = toJson(0,len(str))
    Travese(res)
    print(json.dumps(res))

z='z { x: 3 } z { x:4 }'
solve(z)