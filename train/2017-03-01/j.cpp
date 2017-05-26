#define LOCAL

#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
const int inf = 1e9+5;
const int maxn = 1e5+5;
long long gcd(long long a,long long b){
     return b ? gcd ( b,a%b) : a;
}
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
                if(gcd((long long )a,(long long )b)==1)
                cout<< "GOOD" << endl;
                else cout << "NOT GOOD" << endl;
        }
        return 0;
}



