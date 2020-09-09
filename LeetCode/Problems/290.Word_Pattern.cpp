class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char,string> mmap;
        unordered_map<string,char> rev_map;
        stringstream ss(str);
        string word;
        int i = 0;
        for(i=0;i<pattern.length();++i){
            ss>>word;
            if(rev_map.find(word)==rev_map.end()){
                rev_map[word] = pattern[i];
            }else{
                if(rev_map[word]!=pattern[i]){
                    return false;
                }
            }
            char current = rev_map[word];
            if(mmap.find(current)==mmap.end()){
                mmap[current] = word;
            }else{
                if(word!=mmap[current]){
                    return false;
                }
            }
        }
        if(ss>>word){
            return  false;
        }else if(i!=pattern.length()){
            return false;
        }
        return true;
    }
};
