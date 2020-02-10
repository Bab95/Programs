class Solution {
public:
    int min(int a,int b){
        return a<b?a:b;
    }
    int max(int a,int b){
        return a>b?a:b;
    }
    void search(vector<int>& nums,int start,int end,int target,vector<int>& res){
        if(start>end){
            return;
        }
        int mid = start+(end-start)/2;
        if(nums[mid]==target){
            res[0] = min(res[0],mid);
            res[1] = max(res[1],mid);
            search(nums,start,mid-1,target,res);
            search(nums,mid+1,end,target,res);
        }else if(nums[mid]<target){
            search(nums,mid+1,end,target,res);
        }else{
            search(nums,start,mid-1,target,res);
        }
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        vector<int> result(2);
        result[0] = INT_MAX;
        result[1] = INT_MIN;
        search(nums,low,high,target,result);
        if(result[0]==INT_MAX&&result[1]==INT_MIN){
            result[0] = result[1] = -1;
        }
        return result;
    }
};
