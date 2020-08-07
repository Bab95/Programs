class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();++i){
            if(nums[i]==i+1){
                nums[i] *= -1;
            }
        }
        for(int i=0;i<nums.size();++i){
            int current = nums[i];
            if(current<0){
                continue;
            }
            nums[i] = nums[i]*-1;
            while(current>0){
                int next_index = current-1;
                if(abs(nums[next_index])==current){
                    ans.push_back(current);
                }
                int next = nums[next_index];
                nums[next_index] = -1*current;
                current = next;
            }
        }
        return ans;
    }
};
