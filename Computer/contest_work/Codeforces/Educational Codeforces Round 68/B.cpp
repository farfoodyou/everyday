#include <cstdio>
#include <cstring>

int main(){
    int q;
    int n, m;
    scanf("%d",&q);
    while(q--) {
        int c[1000000], r[1000000];
        memset(c, 0, sizeof(c));
        memset(r, 0, sizeof(r));
        scanf("%d%d",&n,&m);
        getchar();
        for(int i= 0; i< n;i++){
            for(int j = 0; j < m; j++){
                char ch;
                scanf("%c",&ch);
                //printf("%c\t",ch);
                if(ch =='.'){
                    c[i] ++;
                    r[j] ++;
                }
            }
            //puts("");
            getchar();
        }
        int resultC, resultR;
        resultC = resultR = 0;
        int miniC, miniR, miniC_num, miniR_num;
        miniC = miniR = -1;
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
        printf("resultC:  %d\t%d\n", resultC, resultR);
        printf("miniC:  %d\t%d\n", miniC, miniR);
        if(resultC > 0 && resultR > 0) {
            printf("0\n");
            continue;
        } else {
            if(miniC != -1 || miniR != -1) {
                int res = 0;
                res = miniC != -1 ? miniC_num : 0;
                res += miniR != -1 ? miniR_num : 0;
                printf("%d\n", res);
                continue;
            }
            if (miniC == miniR) {
                printf("%d\n", miniC_num + miniR_num -1);
                continue;
            } else {
                printf("%d\n", miniC_num + miniR_num);
                continue;
            }
        }
        printf("ERR\n");
    } 
    return 0;
}