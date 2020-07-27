class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(int i=0;i<nums.size();++i){
            int current = nums[i];
            if(current<0){
                continue;
            }
            while(current>0){
                int next_index = current-1;
                int next = nums[next_index];
                nums[next_index] = -1*current;
                current = next;
            }
        }
        vector<int> ans;
        for(int i=0;i<nums.size();++i){
            if(nums[i]>0){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};
