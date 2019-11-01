class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        vector<int> count(nums.size()+1, 0);  // 长度为 i 的子序列的数量
        dp[0]=1;
        int maxLen = 0;
        for(int i = 1; i< nums.size(); i++) {
            dp[i] = nums[i]>nums[i-1]? dp[i-1]+1:1; 
            if(maxLen < dp[i]) {
                maxLen = dp[i];
            }
        }
        for(int i = 0; i< dp.size(); i++) {
            count[dp[i]]++;
        }
        for(int i = 0; i< dp.size(); i++) {
            std::cout << count[i] << "\n";
        }
        std::cout << maxLen << " len \n";
        return count[maxLen];
        
    }
};

/*

dp[i] = nums[i]>nums[i-1]? dp[i-1]+1 :1; 

dp[i]表示前面连续最长递增子序列长度

错了， 看成最长递增连续子序列了。
*/