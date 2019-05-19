#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int s1[105];
int s2[105];
long long a1,a2;
int l1,l2;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        cin >>a1>>a2;
        //if(a1<a2){long long t= a1;a1 = a2;a2=t;}
        l1=l2=0;
        memset(s1,0,sizeof(s1));
        memset(s2,0,sizeof(s2));
        //printf("1 2 = %lld  %lld\n",a1,a2);

        while(a1){

            if(a1%2==1){s1[l1]=1;}
            a1 = a1/2;
            l1++;
        }
        while(a2){
            if(a2%2==1){s2[l2]=1;}
            a2 = a2/2;
            l2++;
        }
       // for(int j=100;j>=0;j--)if(s1[j]!=0){
       // for(int i = j; i >=0; i--){
       //     printf("%d",s1[i]);
       // }
       // puts("");break;}
       // for(int j=100;j>=0;j--)if(s2[j]!=0){
       // for(int i = j; i >=0; i--){
       //     printf("%d",s2[i]);
        //}
       // puts("");break;}

        for(int i=l1; i>=0;i--){
            if(s1[i]==1&&s2[i]==0){
                for(int j = i;j >=0;j--)s1[j] = 1;
                for(int j = i+2;j <=80;j++)s1[j] = 0;
                break;
            }
        }
        long long ans = 0;
        //for(int j=100;j>=0;j--)if(s1[j]!=0){
        //for(int i = j; i >=0; i--){
        //    printf("%d",s1[i]);
        //}puts("");break;}

        for(int j=80;j>=0;j--)if(s1[j]!=0){
         for(int i = j; i >=0; i--){
             ans = ans * 2;
             ans += s1[i];
         }break;
        }
        cout << ans << endl;
    }
    return 0;
}