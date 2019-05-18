#include <cstdio>
#include <iostream>
#include <map>
#include <unordered_map>


int main(){
    std::unordered_map<std::string,std::string> umap;
    std::string k1("k1"),v1("v1");
    std::string k2("k2"),v2("v2");
    umap[k1] = v1;
    printf("%s\n",umap["k1"].c_str());
    if(umap.find(k2) != umap.end()){
        printf("%s\n",umap["k2"].c_str());
    } else {
        //printf("%s\n",umap.find(k2)->second.c_str());
    }


    return 0;
}