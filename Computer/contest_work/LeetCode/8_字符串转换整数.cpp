class Solution {
public:
    int myAtoi(string str) {
        if(isalpha(str[0])) return 0;
        long long  ans=0;
        int flag=0;// 出现 '-' 置1 
        int len=0;//记录数字的长度   
        int temp=0;//记录 "+-" 出现的次数 
        for (char c:str) {
            //判断 正负号   且数字长度为0  防止 "0-1" 这样的情况 
            if((c=='+' || c=='-') &&len==0) {
                temp++;			//记录符号出现次数 
                flag=(c=='-')? 1:0;
            }
            else if( 0<=(c-'0') && (c-'0')<=9 && temp<2) { 		//temp<2 表示 正负号 只出现过一次 
                ans=ans*10+(c-'0');
                len++;
                // INT_MAX=2147483647 	INT_MIN=-2147483648   
                if(ans-1>INT_MAX) break;		// 如果 数字的绝对值 大于 INT_MAX +1 那么直接跳出 一定溢出 
            } else if(c==' ' && len==0 && temp==0 	)		//如果是空格则继续 但前提是 之前没有出现过 正负号 和 数字 
                continue;
            else		//其他情况：英文和其他字符 
                break;
        }
        if (flag==1)			//flag==1 表示数字为负 
            return -ans<INT_MIN? INT_MIN:-ans;
        return ans>INT_MAX? INT_MAX:ans;
    }
};
