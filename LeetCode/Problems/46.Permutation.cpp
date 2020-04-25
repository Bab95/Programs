class Solution {
public:
    void generate(vector<int>& nums,int index,vector<int>& current,vector<vector<int> >& result){
        if(nums.size()==0){
            result.push_back(current);
            return;
        }
        for(int i=0;i<nums.size();++i){
            int num = nums[i];
            nums.erase(nums.begin()+i);
            current.push_back(num);
            generate(nums,i+1,current,result);
            current.pop_back();
            nums.insert(nums.begin()+i,num);
        }


    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > result;
        vector<int> current;
        int index = 0;
        generate(nums,index,current,result);
        return result;
    }
};
