#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <cmath>  
#include <cstdlib>  
#include <algorithm>  
#include <queue>  
#include <stack>  
#include <map>  
#include <set>  
#include <vector>  
#include <string>  
#define INF 1000000  
#define eps 1e-8  
#define MAXN (200000+10)  
#define MAXM (100000+10)  
#define Ri(a) scanf("%d", &a)  
#define Rl(a) scanf("%lld", &a)  
#define Rf(a) scanf("%lf", &a)  
#define Rs(a) scanf("%s", a)  
#define Pi(a) printf("%d\n", (a))  
#define Pf(a) printf("%.2lf\n", (a))  
#define Pl(a) printf("%lld\n", (a))  
#define Ps(a) printf("%s\n", (a))  
#define W(a) while((a)--)  
#define CLR(a, b) memset(a, (b), sizeof(a))  
#define MOD 1000000007  
#define LL long long  
#define lson o<<1, l, mid  
#define rson o<<1|1, mid+1, r  
#define ll o<<1  
#define rr o<<1|1  
#define PI acos(-1.0)  
#pragma comment(linker, "/STACK:102400000,102400000")  
#define fi first  
#define se second  
using namespace std;  
typedef pair<int, int> pii;  
void add(LL &x, LL y)  
{  
    x += y;  
    x %= MOD;  
}  
int n, b, k, X;  
struct Matrix{  
    LL a[110][110];  
};  
Matrix multi(Matrix x, Matrix y)  
{  
    Matrix z; CLR(z.a, 0LL);  
    for(int i = 0; i < X; i++)  
    {  
        for(int k = 0; k < X; k++)  
        {  
            if(x.a[i][k] == 0) continue;  
            for(int j = 0; j < X; j++)  
                add(z.a[i][j], x.a[i][k] * y.a[k][j]);  
        }  
    }  
    return z;  
}  
Matrix Pow(Matrix x, int n)  
{  
    Matrix y; CLR(y.a, 0LL);  
    for(int i = 0; i < X; i++) y.a[i][i] = 1LL;  
    while(n)  
    {  
        if(n & 1)  
            y = multi(x, y);  
        x = multi(x, x);  
        n >>= 1;  
    }  
    return y;  
}  
int cnt[10];  
int main()  
{  
    Ri(n); Ri(b); Ri(k); Ri(X);  
    Matrix ori, res; CLR(ori.a, 0LL); CLR(cnt, 0);  
    W(n)  
    {  
        int t; Ri(t);  
        cnt[t]++;  
    }  
    for(int i = 0; i < X; i++)  
        for(int j = 0; j <= 9; j++)  
            add(ori.a[i][(i*10+j)%X], 1LL*cnt[j]);  
    res = Pow(ori, b); Pl(res.a[0][k]);  
    return 0;  
}  