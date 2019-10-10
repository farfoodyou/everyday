class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(nums,res,0);
        return res;
    }
    
    void backtrack(vector<int> &nums,vector<vector<int>> &res,int i){
         if(i==nums.size())
             res.push_back(nums);
         for(int j=i;j<nums.size();j++){
             swap(nums[i],nums[j]);
             backtrack(nums,res,i+1);
             swap(nums[i],nums[j]);
         }
     }
};

// 回溯 的全排列算法
