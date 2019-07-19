#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
int c[60000], r[500000];

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

inline bool getcmd()
{
	char t = getchar();
	while(t != '.' && t != '*') t = getchar();
	return t == '.';
}

int main(){
    int q;
    int n, m;
    //scanf("%d",&q);
    _read(q);
    while(q--) {
        //scanf("%d%d",&n,&m);
        _read(n), _read(m);
        memset(c, 0, sizeof(int)*(n+1));
        memset(r, 0, sizeof(int)*(m+1));
        std::vector<std::vector<bool> > mp(n+1, std::vector<bool>(m+1));
        for(int i= 0; i< n;i++){
            for(int j = 0; j < m; j++){
                //printf("%c\t",ch);
                mp[i][j]=getcmd();
            }
        }
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < m; ++j)
				if(mp[i][j]) ++c[i];
		}
		for(int j = 0; j < m; ++j)
		{
			for(int i = 0; i < n; ++i)
			{
				if(mp[i][j]) ++r[j];
            }
        }
        int res = 10000000;
        for(int i = 0; i<n; i++){
            for(int j = 0; j <m; j++) {
                if(c[i] + r[j] - (mp[i][j]? 1:0 ) < res){
                    res = c[i] + r[j] - (mp[i][j]? 1:0 );
                }
            }
        }
        printf("%d\n", res);
    } 
    return 0;
}