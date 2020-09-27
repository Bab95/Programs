class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        if(nums.size()==0||k==0){
            return true;
        }
        int prev = -1;
        for(int i=0;i<nums.size();++i){
            if(nums[i]==1){
                if(prev==-1){
                    prev = i;
                }else{
                    if(i-prev<=k){
                        return false;
                    }else{
                        prev = i;
                    }
                }
            }
        }
        return true;
    }
};
