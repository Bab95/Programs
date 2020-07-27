class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = INT_MAX;
        int low = 0;
        int high = nums.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            ans = min(ans,nums[mid]);
            if(nums[low]<nums[mid]){
                //could be first increasing phase....
                ans = min(ans,nums[low]);
                low = mid + 1;
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
