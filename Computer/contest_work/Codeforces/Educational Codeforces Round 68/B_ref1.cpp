#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void _read(T &x)
{
	x = 0;
	char t = getchar();
	while(!isdigit(t)) t = getchar();
	while(isdigit(t))
	{
		x = x * 10 + t - '0';
		t = getchar();
	}
}
int T;
const int MAXN = 5e5 + 10;
inline bool getcmd()
{
	char t = getchar();
	while(t != '.' && t != '*') t = getchar();
	return t == '*';
}
int num1[MAXN], num2[MAXN];
int main(int argc, char **argv)
{
	_read(T);
	while(T--)
	{
		int n, m;
		_read(n), _read(m);
		vector<vector<bool> > a(n + 1, vector<bool>(m + 1));
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j)
				a[i][j] = getcmd();
		fill(num1, num1 + n + 1, 0);
		fill(num2, num2 + m + 1, 0);
		int maxx = 0, maxcol = 0;
		for(int i = 1; i <= n; ++i)
		{
			for(int j = 1; j <= m; ++j)
				if(a[i][j] == 1) ++num1[i];
		}
		int maxcc = 0;
		maxx = 0;
		for(int j = 1; j <= m; ++j)
		{
			for(int i = 1; i <= n; ++i)
			{
				if(a[i][j] == 1) ++num2[j];
			}
		}
		int mi = 1e9;
		for(int i = 1; i <= n; ++i)
		{
			for(int j = 1; j <= m; ++j)
			{
				if(n - num1[i] + m - num2[j]  - (a[i][j] ^ 1) < mi)
				{
					mi = n - num1[i] + m - num2[j] - (a[i][j] ^ 1);
				}
			}
		}
		printf("%d\n", mi);
	}
	return 0;
}
