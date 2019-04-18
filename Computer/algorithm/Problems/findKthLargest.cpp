int findKthLargest(vector<int>& nums, int k) {
    int left = INT_MAX;
    int right = INT_MIN;
    for(auto x:nums){
        left = min(x,left);
        right = max(x,right);
    }
    while(left<=right){
        int mid = left + (right-left)/2;
        int count1 = 0;
        int count2 = 0;
        for(auto x:nums){
            if(x>=mid)
                count1++;
            if(x>mid)
                count2++;
        }
        if(count1 >=k && count2 <k)
            return mid;
        if(count1 <k)
            right = mid-1;
        else
            left = mid+1;
    }
    return -1;
}


