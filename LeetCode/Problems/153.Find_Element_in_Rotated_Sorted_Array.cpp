class Solution {
public:
    int binarySearch(vector<int>& nums,int start,int end){
        if(start>end){
            return -1;
        }
        if(start==end){
            return start;
        }
        int mid = (start+end)/2;
        if(mid>start&&nums[mid]<nums[mid-1]){
            return mid;
        }
        if(mid<end&&nums[mid]>nums[mid+1]){
            return mid+1;
        }
        if(nums[mid]>nums[start]){
            return binarySearch(nums,mid+1,end);
        }else{
            return binarySearch(nums,start,mid-1);
        }
    }
    int findMin(vector<int>& nums) {
        int ans = binarySearch(nums,0,nums.size()-1);
        cout<<ans<<endl;
        if(ans==nums.size()-1||ans==-1){
            return min(nums[0],nums[nums.size()-1]);
        }
        return nums[ans];
    }
};