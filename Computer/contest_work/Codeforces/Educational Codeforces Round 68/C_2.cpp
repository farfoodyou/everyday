#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
int main(){
    int n;
    std::string s,t,p;
    std::cin >> n;
    while(n--) {
        cin >> s >> t >> p;

        vector<bool> s_ok(s.size()+1, false);
        vector<bool> t_ok(t.size()+1, false);
        vector<int> p_num(30, 0);
        if(s.size()+ p.size()< t.size()){
            puts("NO");
            continue;
        }

        for(int i = 0, j =0 ; i<s.size() && j<t.size();){
            while(s[i] != t[j] && j<t.size()){
                j++;
            }
            if(j == t.size()){
                puts("NO");
                goto nxt;
            }
            s_ok[i] = t_ok[j] = true;
            ++i,++j;
        }
        for(int i = 0; i<s.size(); i++){
            if(!s_ok[i]){
                puts("NO");
                goto nxt;
            }
        }
        for(int i = 0; i< p.size(); i++){
            ++p_num[p[i]-'a'];
        }
        for(int i = 0; i< t.size();++i){
            if(!t_ok[i]){
                if(!p_num[t[i] - 'a']){
                    puts("NO");
                    goto nxt;
                } else {
                    --p_num[t[i] - 'a'];
                }
            }
        }
        puts("YES");
        nxt: {}
    }
    return 0;
}
