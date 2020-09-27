#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = INT_MAX;
        int low = 0;
        int high = nums.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            ans = min(ans,nums[mid]);
            if(nums[low]<nums[mid]){
                //obviously we are in the increasing segment i.e. before pivot element.
                ans = min(ans,nums[low]);
                low = mid+1;
            }else if(nums[mid]<nums[high]){
                ans = min(ans,nums[mid]);
                high = mid-1;
            }else{
                low++;
            }
        }
        return ans;

    }
};