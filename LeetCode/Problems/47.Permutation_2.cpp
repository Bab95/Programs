class Solution {
public:
    void generate(vector<int>& nums,vector<int>& current,set<vector<int> >& ans){
        if(nums.size()==0){
            ans.insert(current);
            return ;
        }
        for(int i=0;i<nums.size();++i){
            int num = nums[i];
            nums.erase(nums.begin()+i);
            current.push_back(num);
            generate(nums,current,ans);

            current.pop_back();
            nums.insert(nums.begin()+i,num);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int> > ans;
        vector<int> current;
        current.reserve(nums.size());
        generate(nums,current,ans);
        vector<vector<int> > result;
        result.insert(result.end(),ans.begin(),ans.end());
        return result;
    }
};
