class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int>> mmap;
        for (auto log : logs) {
            mmap[log[0]].insert(log[1]);
        }
        unordered_map<int, int> count;
        vector<int> result(k);
        for (auto it=mmap.begin();it!=mmap.end();it++){
            int size = it->second.size();
            count[size] += 1;
        }
        for (auto it=count.begin();it!=count.end();it++){
            result[it->first-1] = it->second;
        }
        return result;
    }
};
