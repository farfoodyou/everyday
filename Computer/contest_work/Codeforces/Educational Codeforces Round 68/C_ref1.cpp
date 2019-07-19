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
const int MAXN = 2e2 + 10;
inline bool getcmd()
{
	char t = getchar();
	while(t != '.' && t != '*') t = getchar();
	return t == '*';
}
int ok[MAXN], oka[MAXN];
char s1[MAXN], s2[MAXN], s3[MAXN];
int num[30];
int main(int argc, char **argv)
{
	_read(T);
	while(T--)
	{
		scanf("%s", s1 + 1);
		scanf("%s", s2 + 1);
		scanf("%s", s3 + 1);
		memset(ok, 0, sizeof ok);
		memset(oka, 0, sizeof oka);
		memset(num, 0, sizeof num);
		int len1 = strlen(s1 + 1), len2 = strlen(s2 + 1), len3 = strlen(s3 + 1);
		if (len1 + len3 < len2) puts("NO");
		else
		{
			for (int i = 1, j = 1; i <= len1 && j <= len2; )
			{
				while (s1[i] != s2[j] && j <= len2)
				{
					++j;
				}
				if (j == len2 + 1)
				{
					puts("NO");
					goto nxt;
				}
				ok[j] = 1, oka[i] = 1;
				++i, ++j;
			}
			for (int i = 1; i <= len1; ++i)
			{
				if (!oka[i])
				{
					puts("NO");
					goto nxt;
				}
			}
			for (int i = 1; i <= len3; ++i)
			{
				++num[s3[i] - 'a'];
			}
			for (int i = 1; i <= len2; ++i)
			{
				if (!ok[i])
				{
					if (!num[s2[i] - 'a'])
					{
						puts("NO");
						goto nxt;
					} else --num[s2[i] - 'a'];
				}
			}
			puts("YES");
		}
		nxt: {}
	}
	return 0;
}

