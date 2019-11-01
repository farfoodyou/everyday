class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> res;
        if(intervals.size()==0){
            return intervals;
        }
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int>& b){
            if(a[0]==b[0]){
                return a[1] < b[1];  // 第2个数排，小的在前面
            } else {
                return a[0] < b[0] ;  // 第一个数先排，小的在前面
            }
        });
        res.push_back(intervals[0]);
        for(int i = 1; i< intervals.size(); i++){
            if(res[res.size()-1][1] >= intervals[i][0]) {
                res[res.size()-1][1] = max(intervals[i][1], res[res.size()-1][1]);
                cout  << intervals[i][1] << " merge \n";
            } else {
                res.push_back(intervals[i]);
            }
        }
        
        return res;
    }
};