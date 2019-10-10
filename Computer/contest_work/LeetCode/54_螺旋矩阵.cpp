class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector <int> ans;
        if(matrix.empty()) return ans; //若数组为空，直接返回答案
        ans.resize(matrix.size()*matrix[0].size());
        int u = 0; //赋值上下左右边界
        int d = matrix.size() - 1;
        int l = 0;
        int r = matrix[0].size() - 1;
        int cnt = 0;
        while(true)
        {
            for(int i = l; i <= r; ++i) ans[cnt++] = (matrix[u][i]); //向右移动直到最右
            if(++ u > d) break; //重新设定上边界，若上边界大于下边界，则遍历遍历完成，下同
            for(int i = u; i <= d; ++i) ans[cnt++] = (matrix[i][r]); //向下
            if(-- r < l) break; //重新设定有边界
            for(int i = r; i >= l; --i) ans[cnt++] = (matrix[d][i]); //向左
            if(-- d < u) break; //重新设定下边界
            for(int i = d; i >= u; --i) ans[cnt++] = (matrix[i][l]); //向上
            if(++ l > r) break; //重新设定左边界
        }
        return ans;

    }
};

/*

这题关键在于边界收缩到一条线的时候的处理.
ps: vector 可以resize 大小要先算出来.

*/
