class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size()<=4){
            return 0;
        }
        if(nums.size()<=5){
            sort(nums.begin(),nums.end());
            int ans = INT_MAX;
            for(int i=0;i<nums.size()-1;++i){
                for(int j=i+1;j<nums.size();++j){
                    ans = min(ans,nums[j]-nums[i]);
                }
            }
            return ans;
        }
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int m1 = nums[0];
        int m2 = nums[1];
        int m3 = nums[2];
        int m4 = nums[3];
        int h1 = nums[n-1];
        int h2 = nums[n-2];
        int h3 = nums[n-3];
        int h4 = nums[n-4];
        int ans = INT_MAX;
        ans = min(ans,h4-m1);// top 3 removed...
        ans = min(ans,h3-m2);//top 2 and min..
        ans = min(ans,h2-m3);//bottom 2 and highest..
        ans=  min(ans,h1-m4);//bottom 3....
        return ans;
    }
};
