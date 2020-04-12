class Solution {
public:
    int binarySearch(vector<int>& nums,int start,int end){
        int mid = (start+end)/2;
        if((mid==0||nums[mid]>nums[mid-1])&&(mid==nums.size()-1||nums[mid]>nums[mid+1])){
            return mid;
        }else if(mid>0&&nums[mid]<nums[mid-1]){
            return binarySearch(nums,start,mid-1);
        }
        else if(mid<nums.size()&&nums[mid]<nums[mid+1]){
            return binarySearch(nums,mid+1,end);
        }
        return -1;
    }
    int findPeakElement(vector<int>& nums) {
        int ans = binarySearch(nums,0,nums.size()-1);
        
        return ans;
    }
};