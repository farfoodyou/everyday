class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		int flag = 0;
		vector<int> res;
       for(int i = 0; i <nums.size() && !flag; i++){
		   for(int j = i+1; j< nums.size(); j++){
			   if(nums[i] + nums[j] == target){
				   res.push_back(i);
				   res.push_back(j);
				   flag = 1;
				   break;
				}
		   }
	   }
	   return res;
    }
};
