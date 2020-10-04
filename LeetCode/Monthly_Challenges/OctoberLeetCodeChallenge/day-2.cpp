class Solution {
public:
    void combination_sum_recur(vector<int>& candidates,vector<int>& current,vector<vector<int> >& ans,int i,int target){
        if(target==0){
            ans.push_back(current);
            return;
        }
        if(target<0||i>=candidates.size()){
            return;
        }
        if(target>=candidates[i]){
            current.push_back(candidates[i]);
            combination_sum_recur(candidates,current,ans,i,target-candidates[i]);
            current.pop_back();
        }
        combination_sum_recur(candidates,current,ans,i+1,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> current;
        vector<vector<int> > ans;
        int i = 0;
        combination_sum_recur(candidates,current,ans,i,target);
        return ans;
    }
};
