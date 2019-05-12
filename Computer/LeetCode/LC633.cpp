class Solution {
public:
    bool judgeSquareSum(int c) {
        int end = sqrt(c);
        int start = 0;
        while(start <= end)
        {
            if(start * start == c - end * end)
            {
                return true;
            }
            if(start * start < c - end * end)
            {
                start++;
            }
            else{
                end--;
            }
        }
        return false;
    }
};

/*

*/