#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>

typedef struct node {
    std::string s,t,p;
    struct node():s(""),t(""),p(""){
    }
} status_node;

int main(){
    std::queue<status_node> Q;
    int n;
    std::string s,t,p;
    std::cin >> n;
    while(n--) {
        std::cin >> s >> t >> p;
        status_node head;
        head.s = s;
        head.t = t;
        head.p = p;
        Q.clear();
        Q.push(head);
        bool flag = false;
        while(!Q.empty()) {
             status_node tmp = 
        }
        if (flag) {
            std::cout << "YES\n"; 
        } else {
            std::cout << "NO\n"; 
        }
    }
    return 0;
}