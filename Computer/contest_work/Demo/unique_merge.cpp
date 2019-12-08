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

typedef struct Node{
    int id;
    int val;
    node():id(0),val(10){}
} Node;

int main(){

    int a[] = {3, 4, 5, 6, 100};
    int b[] = {5, 7, 14, 16, 16, 16, 17};
    vector<int> av(a, a+5);
    vector<int> bv(b, b+5);
    vector<int> resv(10);
    int p1, p2, len1, len2;
    p1 = p2 = 0;
    len1 = av.size();

    Node node1, node2;
    

    print1V(resv);
    return 0;
}
