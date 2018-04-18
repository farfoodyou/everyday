#include<stdio.h>
#include<string.h>
bool s[1024];
int main()
{
    int N,M,u,v,i;
    while (scanf("%d%d",&N,&M)!=EOF)
    {
        memset(s,true,sizeof(s));
        for (i=1;i<=M;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            s[u]=false;
            s[v]=false;
        }
        printf("%d\n",N-1);
        for (i=1;i<=N;i++)
        if (s[i])
        {
            u=i;
            break;
        }
        for (i=1;i<=N;i++)
        if (i!=u) printf("%d %d\n",u,i);
    }
    return 0;
}

