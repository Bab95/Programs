class Solution {
public:
    int binarySearch(vector<int>& nums,int start,int end){
        if(start>end){
            cout<<"this";
            return -1;
        }
        int mid = (start+end)/2;
        if(mid%2==1){
            //mid is even...
            if(nums[mid]==nums[mid-1]){
                return binarySearch(nums,mid+1,end); //
            }else{
                return binarySearch(nums,start,mid-1);
            }
        }else{
            //mid is odd....
            if(mid==0&&nums[mid]!=nums[mid+1]){
                return nums[mid];
            }
            if(mid<nums.size()&&nums[mid]==nums[mid+1]){
                return binarySearch(nums,mid+1,end);
            }else if(mid<nums.size()&&nums[mid]!=nums[mid-1]&&nums[mid]!=nums[mid+1]){
                return nums[mid];
            }else{
                return binarySearch(nums,start,mid-1);
            }
        }
        return -1;
    }
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        int res = binarySearch(nums,0,nums.size()-1);
        return res;
    }
};
