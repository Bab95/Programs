class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_map<int,int> mmap;
        for(int i=0;i<n;++i){
            mmap[i] = 0;
        }
        for(auto it : edges){
            mmap[it[1]]++;
        }
        vector<int> ans;
        for(auto it=mmap.begin();it!=mmap.end();++it){
            if(it->second==0){
                ans.push_back(it->first);
            }
        }
        return ans;
    }
};
