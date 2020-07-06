class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int sum = 0;
        int prev_zero = -1;
        int zero_count = 0;
        int max_ans = -1;
        int sum_till_prev_zero = 0;
        for(int i=0;i<nums.size();++i){
            if(nums[i]==0&&zero_count==1){
                max_ans = max(max_ans,sum);
                sum = sum-sum_till_prev_zero;
                sum_till_prev_zero = sum;
                //sum+=1;
                prev_zero = i;
            }else if(nums[i]==0&&zero_count==0){
                prev_zero = i;
                zero_count = 1;
                //sum += 1;
                //sum_till_prev_zero += 1;
            }else if(nums[i]==1){
                if(zero_count==0){
                    sum_till_prev_zero += 1;
                }
                sum += 1;
            }
        }
        max_ans = max(sum,max_ans);
        if(zero_count==0){
            max_ans-=1;
        }
        return max_ans;
    }
};
