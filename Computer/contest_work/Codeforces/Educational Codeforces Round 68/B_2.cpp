#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
int c[60000], r[500000];

int main(){
    int q;
    int n, m;
    scanf("%d",&q);
    std::vector<std::vector<char> > mp(60000, std::vector<char>(10));
    while(q--) {
        memset(c, 0, sizeof(c));
        memset(r, 0, sizeof(r));
        scanf("%d%d",&n,&m);
        getchar();
        for(int i= 0; i< n;i++){
            if(mp[i].size()< m) {
                mp[i].resize(m+1);
            }
            for(int j = 0; j < m; j++){
                char ch;
                scanf("%c",&ch);
                //printf("%c\t",ch);
                if(ch =='.'){
                    c[i] ++;
                    r[j] ++;
                    mp[i][j] = '.';
                } else {
                    mp[i][j] = '*';
                }
            }
            //puts("");
            getchar();
        }
        int resultC, resultR;
        resultC = resultR = 0;
        int miniC, miniR, miniC_num, miniR_num;
        miniC = -2;
        miniR = -1;
        miniC_num = miniR_num = 10000000;
        for(int i = 0; i<n; i++){
            if(c[i] == 0){
                resultC++;
            }
            if(c[i] < miniC_num) {
                miniC = i;
                miniC_num = c[i];
            }
        }
        for(int i = 0; i<m; i++){
            if(r[i] == 0){
                resultR++;
            }
            if(r[i] < miniR_num) {
                miniR = i;
                miniR_num = r[i];
            }
        }
        //printf("resultC:  %d\t%d\n", resultC, resultR);
        //printf("miniC:  %d\t%d\n", miniC, miniR);
        
        if(n == 1){
            printf("%d\n", c[0]);
            continue;
        }
        if(m == 1){
            printf("%d\n", r[0]);
            continue;
        }
        if (miniC_num == 0 && miniR_num == 0){
            printf("%d\n", 0);
            continue;
        }
        int res = 0;
        res = miniC != -2 ? miniC_num : 0;
        res += miniR != -1 ? miniR_num : 0;
        if(mp[miniC][miniR]=='.' && miniC_num > 0 && miniR_num > 0) {
            res -=1;
        }
        printf("%d\n", res);
    } 
    return 0;
}