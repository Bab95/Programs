class Solution {
public:
    int findpivot(vector<int>& nums,int low,int high){
        if(low>high){
            return -1;
        }
        if(low==high){
            return low;
        }
        int mid = (low+high)/2;
        if(mid<high&&nums[mid]>nums[mid+1]){
            return mid;
        }
        if(mid>low&&nums[mid]<nums[mid-1]){
            return mid-1;
        }
        if(nums[low]>=nums[mid]){
            return findpivot(nums,low,mid-1);
        }
        return findpivot(nums,mid+1,high);
    }
    int binarySearch(vector<int>& nums,int low,int high,int target){
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]<target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int high = nums.size()-1;
        int low = 0;
        //findpivot(nums,low,high)<<endl;
        int pivot = findpivot(nums,low,high);
        cout<<"pivot: "<<pivot<<endl;
        if(pivot==-1||pivot==high){
            return binarySearch(nums,low,high,target);
        }
        if(nums[pivot]==target){
            return pivot;
        }
        if(nums[low]<=target){
            return binarySearch(nums,low,pivot-1,target);
        }
        return binarySearch(nums,pivot+1,high,target);
    }
};
