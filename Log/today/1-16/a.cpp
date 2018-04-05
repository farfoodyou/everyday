
#define LOCAL
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 500005;
#define ll long long
int num[500005];
int N,X;
int main()  
{  
    int t;
    scanf("%d",&t);
    while(t--){
       scanf("%d%d",&N,&X);
       ll p,q,sum;
       int len = maxn;
       for( q <= N  ){
          
           if(sum < X ){
              if(num[q] > 0 && num[p])
                 sum += num[q];
           }else if(sum > X && num[q]<0){
              sum += num[q];
           }
       }
    } 
    return 0;  
}  