class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int res=0;
        while(i<j)
        {
             //容量由最小的决定
            int temp1=min(height[i],height[j]);  
            int temp2=temp1*(j-i);
            res=max(res,temp2);
            if(height[i]<height[j])
                i++;
            else j--;
        }
        return res;

    }
};

