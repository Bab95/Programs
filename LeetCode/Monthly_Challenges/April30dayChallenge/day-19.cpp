class Solution {
public:
    int findPivot(vector<int>& nums,int start,int end){
        if(start>end){
            return -1;
        }
        int mid = start+(end-start)/2;
        if(mid<end&&nums[mid]>nums[mid+1]){
            return mid+1;
        }
        if(mid>start&&nums[mid]<nums[mid-1]){
            return mid-1;
        }
        if(nums[mid]>nums[start]){
            return findPivot(nums,mid+1,end);
        }
        return findPivot(nums,start,mid-1);
    }
    int binarySearch(vector<int>& nums,int start,int end,int target){
        if(start>end){
            return -1;
        }
        int mid = start+(end-start)/2;
        if(nums[mid]==target){
            return mid;
        }else if(nums[mid]>target){
            return binarySearch(nums,start,mid-1,target);
        }
        return binarySearch(nums,mid+1,end,target);
    }
    int search(vector<int>& nums, int target) {
        if(nums.size()==0){
            return -1;
        }
        int pivot = findPivot(nums,0,nums.size()-1);
        cout<<pivot<<endl;
        if(pivot==-1){
            return binarySearch(nums,0,nums.size()-1,target);
        }
        if(target==nums[pivot]){
            return pivot;
        }else if(target>=nums[0]){
            return binarySearch(nums,0,pivot-1,target);
        }else{
            return binarySearch(nums,pivot+1,nums.size()-1,target);
        }
        return -1;
    }
};
