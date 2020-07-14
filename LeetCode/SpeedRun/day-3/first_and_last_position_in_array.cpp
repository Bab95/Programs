class Solution {
public:
    void binary_Search(vector<int>& nums,int target,int low,int high,vector<int>& ans){
        //cout<<"("<<low<<","<<high<<")"<<endl;
        if(low>high){
            return;
        }
        int mid = (low+high)/2;
        if(nums[mid]==target){
            ans[0] = min(ans[0],mid);
            ans[1] = max(ans[1],mid);
            binary_Search(nums,target,low,mid-1,ans);
            binary_Search(nums,target,mid+1,high,ans);
        }else if(nums[mid]>target){
            binary_Search(nums,target,low,mid-1,ans);
        }else{
            binary_Search(nums,target,mid+1,high,ans);
        }
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0){
            return {-1,-1};
        }
        vector<int> ans = {INT_MAX,INT_MIN};
        binary_Search(nums,target,0,nums.size()-1,ans);
        if(ans[0]==INT_MAX&&ans[1]==INT_MIN){
            return {-1,-1};
        }
        return ans;
    }
};
