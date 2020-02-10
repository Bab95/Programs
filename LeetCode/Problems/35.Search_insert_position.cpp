class Solution {
public:
    int myBsearch(vector<int>& nums,int start,int end,int target){
        if(start>end){
            return start;
        }
        if(start==end){
            if(nums[start]<target){
                return end+1;
            }else if(nums[start]==target){
                return start;
            }else if(nums[start]>target){
                return start;
            }
        }
        int mid = start+(end-start)/2;
        if(nums[mid]==target){
            return mid;
        }else if(nums[mid]<target){
            return myBsearch(nums,mid+1,end,target);
        }else{
            return myBsearch(nums,start,mid-1,target);
        }
        return -1;
    }
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int result = myBsearch(nums,0,n-1,target);
        return result;
    }
};
