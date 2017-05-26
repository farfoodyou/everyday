#define LOCAL

#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
const int inf = 1e9+5;
const int maxn = 1e5+5;

int main(){
  #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
  #endif
        int cases;
        scanf("%d",&cases);
        while(cases--) {
                int a,b;
                cin >> a >> b;

                cout<< (long long )a*(long long)b << endl;
        }
        return 0;
}



