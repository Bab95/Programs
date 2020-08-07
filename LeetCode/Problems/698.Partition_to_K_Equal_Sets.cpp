class Solution {
public:
    bool can_partition_recursive(vector<int>& nums,vector<bool>& visited,int current_sum,int req_sum,int index,int sets){
        if(sets==0){
            return true;
        }
        if(current_sum==req_sum){
            return can_partition_recursive(nums,visited,0,req_sum,0,sets-1);
        }
        for(int i=index;i<nums.size();++i){
            if(!visited[i]&&current_sum+nums[i]<=req_sum){
                visited[i] = true;
                bool current_ans = can_partition_recursive(nums,visited,current_sum+nums[i],req_sum,i+1,sets);
                if(current_ans){
                   return true;
                }else{
                    //this will be useful in someother set may be in the future.....
                    visited[i] = false;
                }
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if(k==1){
            return true;
        }
        int sum = nums[0];
        int max_element = nums[0];
        for(int i=1;i<nums.size();++i){
            sum += nums[i];
            max_element = max(max_element,nums[i]);
        }

        if(sum%k!=0||max_element>sum/k){
            return false;
        }
        vector<bool> visited(nums.size(),false);
        int current_sum = 0;
        int req_sum = sum/k;
        int index = 0;
        int sets = k;
        return can_partition_recursive(nums,visited,current_sum,req_sum,index,sets);

    }
};
