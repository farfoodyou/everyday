#define LOCAL

#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
const int inf = 1e9+5;
const int maxn = 1e5+5;
map<char,int>mp;
int main(){
  #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
  #endif
        int cases,cnt;
        string s,p;
        scanf("%d",&cases);
        while(cases--) {
                cin >> s;
                char c;
                for(int i = 0; i<s.size(); i++)
                  mp[s[i]]++;
                cnt = 0;
                for(int i = 'a'; i <= 'z' ; i++){
                  if(mp[i]%2==1){
                    cnt ++;
                    c = i;
                  }
                }
                p = "";
                if(cnt <= 1){
                  if(cnt){
                    p += c;
                    mp[c]--;
                  }
                  for(char x= 'z'; x>= 'a'; x--){
                    while(mp[x] > 0){
                      p = x+p+x;
                      mp[x] -=2;
                    }
                  }
                  cout <<p <<endl;
                }
                else
                cout<<  "impossible"<< endl;
                mp.clear();
        }
        return 0;
}



