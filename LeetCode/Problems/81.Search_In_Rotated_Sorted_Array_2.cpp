class Solution {
public:
    bool binarySearch(vector<int>& nums,int low,int high,int target){
        if(low>high){
            return false;
        }
        int mid = (low+high)/2;
        if(target==nums[mid]){
            return true;
        }
        if(nums[low]<nums[mid]){
            if(nums[low]<=target&&target<=nums[mid]){
                return binarySearch(nums,low,mid-1,target);
            }
            return binarySearch(nums,mid+1,high,target);
        }else if(nums[low]>nums[mid]){
            if(target>=nums[mid]&&target<=nums[high]){
                return binarySearch(nums,mid+1,high,target);
            }
            return binarySearch(nums,low,mid-1,target);
        }else{
            return binarySearch(nums,low+1,high,target);
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
        return binarySearch(nums,0,nums.size()-1,target);
    }
};
