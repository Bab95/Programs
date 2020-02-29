class Solution {
public:
    int min(int a,int b){
        return a<b?a:b;
    }
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int k=0;k<nums.size();k++){
            if(nums[k]==k+1){
                nums[k] = INT_MIN;
                continue;
            }
            if(nums[k]!=INT_MIN&&nums[k]>0&&nums[k]<=n){
                int index = nums[k]-1;
                if(nums[index]==INT_MIN){
                    continue;
                }
                while(index>=0){
                    int tmp = nums[index];
                    nums[index] = INT_MIN;
                    if(tmp==INT_MIN||tmp>n){
                        break;
                    }
                    index = tmp-1;
                }
            }
        }

        int ans = n+1;
        for(int i=0;i<n;i++){
            if(nums[i]!=INT_MIN)
                ans = min(ans,i+1);
            cout<<nums[i]<<" ";
        }
        return ans;

    }
};
