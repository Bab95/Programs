class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string> > my_map;
        for(int i=0;i<strs.size();i++){
            string tmp_s = strs[i];
            sort(tmp_s.begin(),tmp_s.end());
            my_map[tmp_s].push_back(strs[i]);
        }
        unordered_map<string,vector<string> >::iterator itr;
        vector<vector<string> > result;
        for(itr=my_map.begin();itr!=my_map.end();++itr){
            vector<string> tmp_vec;
            for(vector<string>::iterator it = itr->second.begin();it!=itr->second.end();++it){
                tmp_vec.push_back(*it);
            }
            result.push_back(tmp_vec);
        }
        return result;
    }
};
