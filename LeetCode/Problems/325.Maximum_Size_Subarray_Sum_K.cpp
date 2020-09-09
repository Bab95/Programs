class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int,int> mmap;
        int sum = 0;
        int ans = 0;
        for(int i=0;i<nums.size();++i){
            sum += nums[i];
            if(sum==k){
                ans = i+1;
            }
            if(mmap.find(sum-k)!=mmap.end()){
                ans = max(ans,i-mmap[sum-k]);
            }
            if(mmap.find(sum)==mmap.end())
                mmap[sum] = i;
        }
        /*
        for(auto it=mmap.begin();it!=mmap.end();++it){
            cout<<it->first<<" "<<it->second<<endl;
        }*/
        return ans;
    }
};
/*
[1,-1,5,-2,3]
3
[-2,-1,2,1]
1
*/
