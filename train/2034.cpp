#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
const int inf = 1e9+5;
const int maxn = 1e5+5;
int N,M;
int main(){
        set<int> a;
        int num[maxn];
        //freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);
        while(scanf("%d%d",&N,&M)==2&&!(N==0&&M==0)) {
                a.clear();
                for(int i = 1; i<= N; i++) {
                        scanf("%d",&num[i]);
                }
                sort(num+1,num+N+1);
                for(int i = 1; i<= M; i++) {
                        int t;
                        scanf("%d",&t);
                        a.insert(t);
                }
                int empty = 0;
                for(int i = 1; i <= N; i++) {
                        if(a.count(num[i])==0) {
                                printf("%d ",num[i]);
                                
                        }else empty++;
                }
                if(empty==N) printf("NULL");
                printf("\n");
        }
        return 0;
}
