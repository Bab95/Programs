class Solution {
public:
    void find_combination(vector<int>& nums,vector<vector<int> >& res,vector<int>& ans,int sum,int k,int i){
        //cout<<"("<<sum<<","<<i<<")"<<endl;
        if(ans.size()==k){
            if(sum==0){
                res.push_back(ans);
            }
            return;
        }
        if(i<0){
            return;
        }
        if(nums[i]<=sum){
            ans.push_back(nums[i]);
            find_combination(nums,res,ans,sum-nums[i],k,i-1);
            ans.pop_back();
        }
        find_combination(nums,res,ans,sum,k,i-1);

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        vector<int> ans;
        vector<vector<int> > res;
        int i = nums.size()-1;
        find_combination(nums,res,ans,n,k,i);
        for(int i=0;i<res.size();++i){
            sort(res[i].begin(),res[i].end());
        }
        return res;
    }
};
