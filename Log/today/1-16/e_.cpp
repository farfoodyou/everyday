#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
using namespace std;
ll n,m,t;
ll ans;
ll combine1(ll n,ll m) //计算组合数C(n,m)
{
    ll sum=1; //线性计算
    for(ll i=1,j=n;i<=m;i++,j--)
        sum=sum*j/i;
    return sum;
}
int main()
{
    scanf("%I64d %I64d %I64d",&n,&m,&t);
    for(int i=4;i<=t-1;i++)
    {
        ans=ans+combine1(n,i)*combine1(m,t-i);
    }
    printf("%I64d\n",ans);
}

