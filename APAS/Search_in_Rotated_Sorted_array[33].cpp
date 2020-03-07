class Solution {
public:
    int binarySearch(vector<int>& nums,int low,int high,int target){
        if(low>high){
            return -1;
        }
        int mid = (low+high)/2;
        if(target==nums[mid]){
            return mid;
        }
        if(nums[low]<=nums[mid]){
            if(target>=nums[low]&&target<=nums[mid]){
                return binarySearch(nums,low,mid-1,target);
            }
            return binarySearch(nums,mid+1,high,target);
        }
        if(target>=nums[mid]&&target<=nums[high]){
                return binarySearch(nums,mid+1,high,target);
        }

        return binarySearch(nums,low,mid-1,target);
    }
    int search(vector<int>& nums, int target) {
        int res = binarySearch(nums,0,nums.size()-1,target);
        return res;
    }
};
