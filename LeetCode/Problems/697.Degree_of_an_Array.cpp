class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,vector<int> > mmap;
        for(int i=0;i<nums.size();++i){
            mmap[nums[i]].push_back(i);
        }
        int maxfreq = 0;
        int ans = INT_MAX;
        for(auto it=mmap.begin();it!=mmap.end();++it){
            if(it->second.size()>maxfreq){
                ans = it->second[it->second.size()-1]-it->second[0] + 1;
                maxfreq = it->second.size();
            }else if(it->second.size()==maxfreq){
                int window = it->second[it->second.size()-1]-it->second[0] + 1;
                ans = min(window,ans);
            }
        }

        return ans;

    }
};
