class Solution {
public:
    struct _hash_pair{
        template <class T1,class T2>
        size_t operator()(const pair<T1,T2>& p){
            size_t h1 = hash<T1>(p.first);
            size_t h2 = hash<T2>(p.second);
            return h1^h2;
        }
    };
    int findPairs(vector<int>& nums, int k) {
        if(k<0){
            return 0;
        }
        unordered_map<int,int> mmap;
        for(int i=0;i<nums.size();++i){
            mmap[nums[i]]+=1;
        }
        int ans = 0;
        //unordered_set<pair<int,int>,_hash_pair> pairs;
        set<pair<int,int> > pairs;
        for(int i=0;i<nums.size();++i){
            int a = nums[i] + k;
            int b = nums[i] - k;
            mmap[nums[i]] -= 1;
            if(mmap.find(a)!=mmap.end()&&mmap[a]>=1){
                pairs.insert({min(a,nums[i]),max(a,nums[i])});
            }
            if(mmap.find(b)!=mmap.end()&&mmap[b]>=1){
                pairs.insert({min(b,nums[i]),max(b,nums[i])});
            }
        }
        return pairs.size();
    }
};
