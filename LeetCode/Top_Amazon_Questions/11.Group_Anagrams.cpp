class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > anagrams;
        int index = 0;
        unordered_map<string,int> mmap;
        for(int i=0;i<strs.size();++i){
            string tmp = strs[i];
            sort(tmp.begin(),tmp.end());
            if(mmap.find(tmp)==mmap.end()){
                mmap[tmp] = index;
                index+=1;
                anagrams.push_back(vector<string>());
            }
            anagrams[mmap[tmp]].push_back(strs[i]);
        }
        return anagrams;
    }
};
