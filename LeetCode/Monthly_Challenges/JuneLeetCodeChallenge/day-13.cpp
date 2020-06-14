class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size()==0){
            return nums;
        }
        sort(nums.begin(),nums.end());
        vector<int> count(nums.size(),1);
        for(int i=1;i<nums.size();++i){
            for(int j=i-1;j>=0;j--){
                if(nums[i]%nums[j]==0){
                    count[i] = max(count[i],count[j]+1);
                }
            }

        }

        int max_index=0,max_count=0;
        for(int i=0;i<count.size();++i){
            if(count[i]>max_count){
                max_count = count[i];
                max_index = i;
            }
        }

        int current_num = nums[max_index];
        vector<int> ans;
        for(int i=max_index;i>=0;i--){
            if((current_num%nums[i]==0)&&count[i]==max_count){
                ans.push_back(nums[i]);
                current_num = nums[i];
                max_count--;
            }
        }

        return ans;
    }

};
