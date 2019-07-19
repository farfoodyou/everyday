#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void _read(T &x)
{
	x = 0;
	char t = getchar();
	while (!isdigit(t)) t = getchar();
	while (isdigit(t))
	{
		x = x * 10 + t - '0';
		t = getchar();
	}
}
int T;
int main(int argc, char **argv)
{
	_read(T);
 
	while (T--)
	{
		int n, x;
		_read(n), _read(x);
		printf("%d\n", 2 * x);
	}
	return 0;
}
