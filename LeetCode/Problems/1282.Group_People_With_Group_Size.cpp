class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int,vector<int>> groups;
        int _maxGroupSize = 0;
        for (int i=0;i<groupSizes.size();i++){
            if (groups.find(groupSizes[i]) == groups.end()){
                groups[groupSizes[i]] = vector<int>();
            }
            _maxGroupSize = max(_maxGroupSize, groupSizes[i]);
            groups[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> result;
        for(int i=0;i<=_maxGroupSize;i++){
            if (groups.find(i) != groups.end()){
                if (groups[i].size() == i){
                    result.push_back(groups[i]);
                }else{
                    int k =0;
                    vector<int> tmp;
                    while (k < groups[i].size()){
                        tmp.push_back(groups[i][k]);
                        k++;
                        if (k%i==0){
                            result.push_back(tmp);
                            tmp.clear();
                        }
                    }
                }
            }
        }
        return result;
    }
};
