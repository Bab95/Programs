class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        unordered_map<int,vector<int> > mmap;
        for(auto &it:items){
            mmap[it[0]].push_back(it[1]);
        }
        vector<vector<int> > ans;
        for(auto it=mmap.begin();it!=mmap.end();++it){
            sort(it->second.rbegin(),it->second.rend());
            int sum = 0;
            for(int i=0;i<min((int)it->second.size(),5);++i){
                sum += it->second[i];
            }
            sum = sum/min((int)it->second.size(),5);
            ans.push_back({it->first,sum});
        }
        sort(ans.begin(),ans.end());
        return ans;

    }
};
