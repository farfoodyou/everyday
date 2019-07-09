#include <stack>
#include <vector>
#include <iostream>
#include <cstdlib>

int top, S[10000];

void push(int x){
    S[++top] = x;
}

int pop(){
    top--;
    return S[top+1];
}

int main(){
    int a, b;
    top = 0;
    char s[100];
    while(scanf("%s", s) != EOF){
        if(s[0] == '+') {
            a = pop();
            b = pop();
            push(a+b);
        } else if(s[0] == '-') {
            a = pop();
            b = pop();
            push(a-b);
        } else if(s[0] == '*') {
            a = pop();
            b = pop();
            push(a*b);
        } else {
            push(atoi(s));
        }
    }
    std::cout << pop() << std::endl;
    return 0;
}

/* 
 * 2019-07-09 复习了
 * 1. 将字符串转化成 int 的 atoi 函数
 * 2. while (scanf("%s", s) != EOF) {} 这种输入方式
 * 3. 屏幕输入 CTRL + D 屏幕中输入 EOF 来结束 
 *    或者 echo '8 9 + 8 6 - *' | ./a.out 这种方式
 */