auto fast_io =[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int i = 1, j = 0, n = s.size();
        vector<int> dp(n+1,0);
        while( i < s.size() ){
            if( s[i] == s[j] ) dp[++i]=++j;
            else if( j == 0 ) i++;
            else j = dp[j];
        }
        return dp[n]&&dp[n]%(n-dp[n])==0;
        /*
        // -1 本身不算子串
        for (int i = 0; i < s.size()-1; i++) {
            if (checkSubString(s, 0, i)) {
                //cout << " sucess " << i << endl;
                return true;
            }
        }
        */
        //return false;
    }
    /*
    bool checkSubString(const string &s, int first, int last) {
        int len = last - first + 1;
        // 检查子串长度是否满足
        int lastLen = s.size() - first;
        //cout << len << " " << lastLen << endl;
        if (lastLen % len != 0) {
            return false;
        }
        for(int i = first; i<= last; i++) {
            if(!checkch(s, i, len)) {
                return false;
            }
        }
        return true;
    }
    bool checkch(const string &s, int pos, int len) {
        char firstChar = s[pos];
        for (int i = pos; i <s.size(); i+=len) {
            //cout << s[i] << " " << endl;
            if (s[i] != firstChar) {
                return false;
            }
        }
        return true;
    }
    */
    
};


/*
暴力: N^2
    需求: 判断一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。
    简单分析:
        只一个子串重复多次构成, 一定需要满足左开始, 
        遍历检查每个子串尝试能够从左重复到右边即可.
    基本设计:
        用 first, last 表示子串开始位置, 子串结束位置(最后一个字符)
        for i int len(str)/2:
            if(checkSubString(str, 0, i)):
                return true;
        return false;
        
        API:
            input: 字符串string, 子串开始位置, 子串结束位置(最后一个字符)
            ouput: 子串能够重复构成.
            description: 子串是否能够构造s,first之后的部分
            bool checkSubString(string s, int first, int last);
第一次: 没考虑子串长度能够整除的问题 错了 5,6次
第二次: debug后发现 本身是否是子串的问题,
第三次: 超时, 注释掉cout 后60 ms, 在Repeated Substring Pattern的C++提交中击败了60.70% 的用户
感觉还能优化
开了fast_io后 32 ms, 在Repeated Substring Pattern的C++提交中击败了98.93% 的用户
用了DP 之后 20 ms, 在Repeated Substring Pattern的C++提交中击败了99.73% 的用户

*/