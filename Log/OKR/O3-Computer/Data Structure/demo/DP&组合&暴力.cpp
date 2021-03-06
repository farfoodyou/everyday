#include <cstdio>
#include <cstring>
#include <algorithm>
const int maxn = 105;
/* 结果如下
总方案数是 512
DP算法结果为 256
暴力算法结果为 256
数学解法结果为 256
*/
// 共计三种方式

// 动态规划复杂度 O(n*m)
// 这里为了DP方便表示状态，给所有分值加上 1 分，
// 问题转化为9个选择，分值大于等于 9 + 5 = 14 的方案数
int value[10][2] = {
    {0,0},{3,1},{3,1},{3,1},{3,1},
    {2,0},{2,0},{2,0},{2,0},{2,0}
}; 
int dp[maxn][maxn]; //dp[i][j] 表示第i件物品，分值为 j 时的方案数
int DP(){
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1; //至少有一种方案。
    for(int i = 1; i<=9; i++){
        for(int j = 1; j<= 100; j++){
            if(j-value[i][0]>=0)
                dp[i][j] += dp[i-1][j-value[i][0]];
            if(j-value[i][1]>=0)
                dp[i][j] += dp[i-1][j-value[i][1]];
        }
    }
    int sum = 0;
    int _sum = 0;
    for(int i = 0; i<=100; i++){
        if(i >= 14)
            sum += dp[9][i];
        _sum += dp[9][i];
    }
    printf("总方案数是 %d\n",_sum);
    return sum;
}

// 复杂度 O(2^n)
int force(int i,int v){
    if(i == 9 ){
        int res = 0;
        if(v + value[9][0]>= 14)res++;
        if(v + value[9][1]>= 14)res++;
        return res;
    } else {
        return force(i+1,v + value[i][0]) + force(i+1,v + value[i][1]);
    }
    return -1;
}

//从n个中选取k个
int Com(int n,int k){
    if (k==0 || k==n)
        return 1;
    else
        return Com(n-1,k)+Com(n-1,k-1);
}
// 数学解法 排列组合
int math(){
    /* 分成两组 
    *  第一组 分值可为 0, 2, 4, 6, 8 分别为选 0 1，2，3，4 个正向的情况
    *  第二组 分值可为 -5,-3，-1,1,3,5 分别为选 0，1，2，3，4，5，个正向情况
    *  分值组合为:
    *  (0,5),(2,5),(2,3),(4,1),(4,3),(4,5),(6,-1),(6,1),(6,3),(6,5)
    *  (8,-3),(8,-1),(8,1),(8,3),(8,5)
    */
    return Com(4,0)*Com(5,5)+Com(4,1)*Com(5,4)+Com(4,1)*Com(5,5)+
            Com(4,2)*Com(5,3)+Com(4,2)*Com(5,4)+Com(4,2)*Com(5,5)+
            Com(4,3)*Com(5,2)+Com(4,3)*Com(5,3)+Com(4,3)*Com(5,4)+
            Com(4,3)*Com(5,5)+Com(4,4)*Com(5,1)+Com(4,4)*Com(5,2)+
            Com(4,4)*Com(5,3)+Com(4,4)*Com(5,4)+Com(4,4)*Com(5,5);
}
int main(){

    printf("DP算法结果为 %d\n", DP());
    printf("暴力算法结果为 %d\n", force(1,0));
    printf("数学解法结果为 %d\n", math());
    return 0;
}

/*
题号：15
在一款恋爱模拟游戏中，男主角进入了某个女主角的线路，现在遵循“与其约会，使其娇羞”的战略，共有9个约会场所提供使用。其中，有四个约会场景，较为浪漫，男主可以取得好感度+2或者好感度+0，五个约会场景较为普通，男主可以取得好感度+1或者好感度-1。在男主角使用所有约会场景之后，女主角好感度达到5及其以上，可以进入happy end，否则攻略失败，请输出男主能攻略成功女主的方法总数。 例如，在所有场景中均取得正向的好感度，那么总好感度为+13>=5，为其中一种攻略方案。
要求：
1.代码严谨，逻辑清晰，为给审核人员提供方便，请使用相关注释，算法要求能运行后输出正确数值结果。
2.组合数的公式使用递归定义。
请给具体实现代码,并在答案后附上自我介绍（学校-专业-姓名），谢谢！
答案及自我介绍可以粘贴在paste.ubuntu.com等网站,并将生成的网址粘贴到QQ验证窗口。
*/