class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,int> mmap;
        //sorted_string to its index in vector of vectors
        vector<vector<string> > result;
        int result_size = 0;
        for(int i=0;i<strs.size();++i){
            string s = strs[i];
            sort(s.begin(),s.end());
            if(mmap.count(s)){
                result[mmap[s]].push_back(strs[i]);
            }else{
                mmap[s] = result_size;
                result_size++;
                result.push_back({strs[i]});
                //result[mmap[s]].push_back(strs[i]);
            }
        }
        return result;
    }
};