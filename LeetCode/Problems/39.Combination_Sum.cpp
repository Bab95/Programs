class Solution {
public:
    void generate(vector<vector<int> >& result,vector<int>& candidates,int target,int n,vector<int>& tmp){
        if(target==0){
            result.push_back(tmp);
            return;
        }
        if(n<0){
            return;
        }
        if(candidates[n]<=target){
            tmp.push_back(candidates[n]);
            generate(result,candidates,target-candidates[n],n,tmp);
            tmp.pop_back();
            generate(result,candidates,target,n-1,tmp);
        }else{
            generate(result,candidates,target,n-1,tmp);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > result;
        vector<int> tmp;
        generate(result,candidates,target,candidates.size()-1,tmp);

        return result;
    }
};
