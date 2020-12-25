class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int ans = 0;
        unordered_map<int,int> mmap;
        for(int i=0;i<time.size();++i){
            mmap[time[i]%60] += 1;
        }
        ans += (mmap[0]*(mmap[0]-1));
        ans /= 2;
        int l = 1;
        int r = 59;
        while(l<r){
            int a = mmap[l];
            int b = mmap[r];
            ans += (a*b);
            l++;
            r--;
        }
        if(mmap[30]>1){
            ans += ((mmap[30]*(mmap[30]-1))/2);
        }
        return ans;
    }
};
