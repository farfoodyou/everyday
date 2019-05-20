#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
const int maxn = 1000;
char str[maxn];
int next[maxn];
void Next(char *T){
    int i = 0, j = -1;
    int len = strlen(T);
    next[0] = -1;
    while(i < len){
        if( j ==-1 || T[i] == T[j]){
            i++; j++; next[i] = j;
        } else {
            j = next[j];
        }
    }
}

void printChar(char *str){
    for(int i = 0; str[i] != '\0'; i++){
        printf("%c ",str[i]);
    }
    printf("\n");
}

void printInt(int *nums){
    int len = 10;
    for(int i = 0; i < len; i++){
        printf("%d ",nums[i]);
    }
    printf("\n");
}

int main(){
    while(gets(str)!=NULL){
        memset(next,0,sizeof(next));
        Next(str);
        printInt(next);
        printf("%s\n","Finish");
    }
    return 0;
}