#define LOCAL

#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
const int inf = 1e9+5;
const int maxn = 1e5+5;

char mp[55][55];
char in[5];

int main(){
  #ifdef LOCAL
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
  #endif
        int cases;
        scanf("%d",&cases);
        while(cases--) {
                int a,b;
                memset(mp,0,sizeof(mp));
                cin >> a >> b;
                for(int i = 0; i < a; i++){
                  for(int j = 0; j < b; j++){
                    scanf("%s",in);
                    mp[i][j] = in[0];
                  }
                }
                int flag = 0;
                for(int i = 0; i < a ; i++){
                  for(int j = 0; j < b ; j++){
                    if(i >=2 && mp[i][j] == 'p' && mp[i-1][j] == 'i' && mp[i-2][j]=='e')flag = 1;
                    if(i < a-2 && mp[i][j] == 'p' && mp[i+1][j] == 'i' && mp[i+2][j]=='e')flag = 1;
                    if(j >=2 && mp[i][j] == 'p' && mp[i][j-1]=='i' && mp[i][j-2]=='e')flag = 1;
                    if(j < b-2 && mp[i][j]=='p' && mp[i][j+1]=='i' && mp[i][j+2]=='e')flag = 1;
                  
                    if(i >=2&& j >=2 && mp[i][j] == 'p' && mp[i-1][j-1] == 'i' && mp[i-2][j-2]=='e')flag = 1;
              if(i < a-2 && j <b-2 && mp[i][j] == 'p' && mp[i+1][j+1] == 'i' && mp[i+2][j+2]=='e')flag = 1;
              if(j >=2&&i < a-2 && mp[i][j] == 'p' && mp[i+1][j-1] == 'i' && mp[i+2][j-2]=='e')flag = 1;    
              if(i >=2&&j < b-2 && mp[i][j] == 'p' && mp[i-1][j+1] == 'i' && mp[i-2][j+2]=='e')flag = 1;
              
                  }
                }
                if(flag ==1){
                  printf("Cutie Pie!\n");
                }else
                printf("Sorry Man\n");
                
        }
        return 0;
}



