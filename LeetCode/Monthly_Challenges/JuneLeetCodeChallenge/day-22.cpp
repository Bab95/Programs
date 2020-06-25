class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> hash(32,0);
        int n = nums.size();
        for(int i=0;i<n;++i){
            int k = 0;
            while(k<32){
                if(nums[i]<0){
                    nums[i] = (int)((long int)pow(2,32) - abs(nums[i]));
                }
                hash[k] += nums[i] & 1;
                hash[k] = hash[k]%3;
                nums[i] = nums[i]>>1;
                ++k;
            }
        }
        long int ans = 0;
        /*for(int i=0;i<32;++i){
            cout<<hash[i]<<" ";
        }*/
        for(int i=0;i<31;++i){
            ans += hash[i]*pow(2,i);
        }
        //cout<<endl<<ans<<endl;
        if(hash[31]==1){
            //number is negative.....
            //cout<<pow(2,31)<<endl;
            ans = ((long int)(pow(2,31))-(long int)ans);
            ans *= -1;
            cout<<ans<<endl;
        }

        return ans;
    }
};
