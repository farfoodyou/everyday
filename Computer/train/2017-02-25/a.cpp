#define LOCAL

#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
const int inf = 1e9+5;
const int maxn = 1e5+5;

map<string,pair<int,int> > mp;

int cha(string s,int v){
  
        int &a = mp[s].first,&b = mp[s].second;
        if(v>b) b = v;
        if(a<b) swap(a,b);
        return 1;
}

int main(){
  #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
  #endif

        int cases,N;
        scanf("%d",&cases);
        while(cases--) {
                scanf("%d",&N);
                string s;
                int v;
                for(int i = 0; i < N; i++) {
                        cin >> s >> v;
                        cha(s,v);
                }
                int ans = 0;
                map<string,pair<int,int> >::iterator it;

                it = mp.begin();
                while(it != mp.end())
                {
                        //it->first;
                        ans += it->second.first;
                        ans += it->second.second;
                        it++;
                }
                mp.clear();

                cout<< ans << endl;
        }
        return 0;
}



