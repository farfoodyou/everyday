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
                long long flag = a*b;
                if(flag % 2 == 0)
                  cout<< "Hasan"<< endl;
                else
                  cout<< "Hussain"<< endl;
        }
        return 0;
}



