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

str = 'rec_input { rec_type: "357" rec_param { rec_id: "357" rec_num: 0 rank_type: RAC_RANK_TYPE_COMMON display_type: RAC_DISPLAY_TYPE_COMMON page: 1 } } rec_input { rec_type: "303" rec_param { rec_id: "303" rec_num: 0 rank_type: RAC_RANK_TYPE_COMMON display_type: RAC_DISPLAY_TYPE_COMMON page: 1 } } rec_input { rec_type: "211" rec_param { rec_id: "211" rec_num: 4 rank_type: RAC_RANK_TYPE_COMMON display_type: RAC_DISPLAY_TYPE_GAME_SMALL_PHOTO page: 1 } } rec_input { rec_type: "212" rec_param { rec_id: "212" rec_num: 5 rank_type: RAC_RANK_TYPE_COMMON display_type: RAC_DISPLAY_TYPE_GAME_SMALL_PHOTO page: 1 } } rec_input { rec_type: "213" rec_param { rec_id: "213" rec_num: 4 rank_type: RAC_RANK_TYPE_COMMON display_type: RAC_DISPLAY_TYPE_GAME_SMALL_PHOTO page: 1 } } rec_input { rec_type: "214" rec_param { rec_id: "214" rec_num: 0 rank_type: RAC_RANK_TYPE_COMMON display_type: RAC_DISPLAY_TYPE_COMMON page: 1 } } rec_input { rec_type: "215" rec_param { rec_id: "215" rec_num: 4 rank_type: RAC_RANK_TYPE_COMMON display_type: RAC_DISPLAY_TYPE_GAME_SMALL_PHOTO page: 1 } } rec_input { rec_type: "216" rec_param { rec_id: "216" rec_num: 4 rank_type: RAC_RANK_TYPE_COMMON display_type: RAC_DISPLAY_TYPE_GAME_SMALL_PHOTO page: 1 } } rec_input { rec_type: "304" rec_param { rec_id: "304" rec_num: 0 rank_type: RAC_RANK_TYPE_COMMON display_type: RAC_DISPLAY_TYPE_COMMON page: 1 } } rec_input { rec_type: "218" rec_param { rec_id: "218" rec_num: 4 rank_type: RAC_RANK_TYPE_COMMON display_type: RAC_DISPLAY_TYPE_GAME_SMALL_PHOTO page: 1 } } rec_input { rec_type: "219" rec_param { rec_id: "219" rec_num: 4 rank_type: RAC_RANK_TYPE_COMMON display_type: RAC_DISPLAY_TYPE_GAME_SMALL_PHOTO page: 1 } } rec_input { rec_type: "220" rec_param { rec_id: "220" rec_num: 0 rank_type: RAC_RANK_TYPE_COMMON display_type: RAC_DISPLAY_TYPE_COMMON page: 1 } } rec_input { rec_type: "221" rec_param { rec_id: "221" rec_num: 4 rank_type: RAC_RANK_TYPE_COMMON display_type: RAC_DISPLAY_TYPE_GAME_SMALL_PHOTO page: 1 } } rec_input { rec_type: "299" rec_param { rec_id: "299" rec_num: 4 rank_type: RAC_RANK_TYPE_COMMON display_type: RAC_DISPLAY_TYPE_GAME_SMALL_PHOTO page: 1 } } rec_input { rec_type: "226" rec_param { rec_id: "226" rec_num: 0 rank_type: RAC_RANK_TYPE_COMMON display_type: RAC_DISPLAY_TYPE_COMMON page: 1 } } rec_input { rec_type: "228" rec_param { rec_id: "228" rec_num: 4 rank_type: RAC_RANK_TYPE_COMMON display_type: RAC_DISPLAY_TYPE_GAME_SMALL_PHOTO page: 1 } } rec_input { rec_type: "229" rec_param { rec_id: "229" rec_num: 4 rank_type: RAC_RANK_TYPE_COMMON display_type: RAC_DISPLAY_TYPE_GAME_SMALL_PHOTO page: 1 } } rec_input { rec_type: "230" rec_param {rec_id: "230" rec_num: 1 rank_type: RAC_RANK_TYPE_COMMON display_type: RAC_DISPLAY_TYPE_GAME_BIG_PHOTO page: 1 } } rec_input { rec_type: "231" rec_param { rec_id: "231" rec_num: 4 rank_type: RAC_RANK_TYPE_COMMON display_type: RAC_DISPLAY_TYPE_GAME_SMALL_PHOTO page: 1 } } rec_input { rec_type: "232" rec_param { rec_id: "232" rec_num: 4 rank_type: RAC_RANK_TYPE_COMMON display_type: RAC_DISPLAY_TYPE_GAME_SMALL_PHOTO page: 1 } } rec_input { rec_type: "233" rec_param { rec_id: "233" rec_num: 1 rank_type: RAC_RANK_TYPE_COMMON display_type: RAC_DISPLAY_TYPE_GAME_BIG_PHOTO page: 1 } } rec_input { rec_type: "234" rec_param { rec_id: "234" rec_num: 4 rank_type: RAC_RANK_TYPE_COMMON display_type: RAC_DISPLAY_TYPE_GAME_SMALL_PHOTO page: 1 } } rec_input { rec_type: "235" rec_param { rec_id: "235" rec_num: 4 rank_type: RAC_RANK_TYPE_COMMON display_type: RAC_DISPLAY_TYPE_GAME_SMALL_PHOTO page: 1 } } rec_input { rec_type: "236" rec_param { rec_id: "236" rec_num: 1 rank_type: RAC_RANK_TYPE_COMMON display_type: RAC_DISPLAY_TYPE_GAME_BIG_PHOTO page: 1 } } rec_input { rec_type: "237" rec_param { rec_id: "237" rec_num: 4 rank_type: RAC_RANK_TYPE_COMMON display_type: RAC_DISPLAY_TYPE_GAME_SMALL_PHOTO page: 1 } } rec_input { rec_type: "238" rec_param { rec_id: "238" rec_num: 4 rank_type: RAC_RANK_TYPE_COMMON display_type: RAC_DISPLAY_TYPE_GAME_SMALL_PHOTO page: 1 } } rec_input { rec_type: "305" rec_param { rec_id: "305" rec_num: 0 rank_type: RAC_RANK_TYPE_COMMON display_type: RAC_DISPLAY_TYPE_COMMON page: 1 } } history_disp { type: "bsp_history_7d" } rec_ctx { system_type: "android" system_version: "9" province: "" city: "" district: "" city_code: "" shoubai_version: "11.7.0.10" shoubai_type: "baidu" refer: "" page: 1 size: 8 channel: "baidu" mini_swan_version: "2.4.0" } ext_param { page_type: GAME_PAGE_TYPE_HOME } '

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
solve(str)
