#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int bfind(int *nums, int left, int right, int target){
    while(left < right){
        int mid = left + (right - left) / 2;
        if(nums[mid] == target){
            return mid;
        }else if(nums[mid] > target){
            right = mid;
        }else {
            left = mid + 1;
        }
    }
    return left;
}

int floorfind(int *nums, int left, int right, int target){
    while(left < right){
        int mid = left + (right - left) / 2;
        if(nums[mid] == target){
            return mid;
        }else if(nums[mid] > target){
            right = mid-1;
        }else {
            left = mid;
        }
    }
    return left;
}

int binary_find(int nums[], int left, int right, int target){
    //printf("%d %d\n", left, right);
    if(left > right){
        return left;
    }
    int mid = left + (right - left) / 2;
    if(nums[mid] == target){
        return mid;
    }else if(nums[mid] < target){
        return binary_find(nums, mid+1, right, target);
    }else {
        return binary_find(nums, left, mid, target);
    }
}

int main(){
    int nums[100];
    for(int i = 0; i < 100; i++){
        nums[i] = i*2;
    }
    int target = 41;
    int result1 = bfind(nums, 0, 100-1, target);
    int result2 = floorfind(nums, 0, 100-1, target);
    int result3 = binary_find(nums, 0, 100-1, 32);
    assert( result3 > 16);
    printf("target is %d locaton1 is %d\n",target, result1);
    printf("the locaton is %d\n", nums[result1]);
    printf("target is %d locaton2 is %d\n",target, result2);
    printf("the locaton is %d\n", nums[result2]);
    printf("target is %d locaton3 is %d\n",target, result3);
    printf("the locaton is %d\n", nums[result3]);
    return 0;
}



