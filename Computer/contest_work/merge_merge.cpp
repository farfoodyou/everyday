#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void print1V(vector<int>  input) {
    for(int j = 0; j< input.size(); j++) {
        if(j)std::cout << " ";
        std::cout << input[j] ;
    }
    std::cout << std::endl;
}

int main(){

    int a[] = {3, 4, 5, 6, 100};
    int b[] = {5, 7, 14, 16, 17};
    vector<int> av(a, a+5);
    vector<int> bv(b, b+5);
    vector<int> resv(10);
    int p1, p2, len1, len2;
    p1 = p2 = 0;
    len1 = av.size();
    len2 = bv.size();
    int p = 0;

    while(p1 < len1 && p2 < len2) {
        if(av[p1]<bv[p2])
            resv[p++] = av[p1++];
        else 
            resv[p++] = bv[p2++];
    }

    if(p1==len1){
        while(p2<len2)
            resv[p++] = bv[p2++];
    } else {
        while(p1<len1)
            resv[p++] = av[p1++];
    }

    print1V(resv);
    return 0;
}

/*
合并两个有序数组

*/
