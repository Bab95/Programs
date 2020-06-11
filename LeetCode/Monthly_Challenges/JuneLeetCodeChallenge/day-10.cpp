class Solution {
public:
    void binary_Search(vector<int>& arr,int low,int high,int k,int &ans){
        if(low<=high){
            int mid = low + (high-low)/2;
            if(k==arr[mid]){
                ans = max(mid-1,0);
                return;
            }else if(arr[mid]>k){
                if(mid>0){
                    if(arr[mid-1]<k){
                        ans = mid-1;
                    }else if(arr[mid-1]==k){
                        ans = max(mid-2,0);
                    }else{
                        binary_Search(arr,low,mid-1,k,ans);
                    }
                }else if(mid==0){
                    ans = 0;
                    return;
                }else{
                        binary_Search(arr,low,mid-1,k,ans);
                }
            }else if(arr[mid]<k){
                if(mid<arr.size()-1&&k<=arr[mid+1]){
                    ans = mid;
                }else if(mid==arr.size()-1){
                    ans = arr.size();
                }else{
                    binary_Search(arr,mid+1,high,k,ans);
                }
            }
        }
    }
    int searchInsert(vector<int>& nums, int target) {
        if(target<=nums[0]){
            return 0;
        }
        if(target>nums[nums.size()-1]){
            return nums.size();
        }
        int res = 0;
        binary_Search(nums,0,nums.size()-1,target,res);
        return res+1;
    }
};
