class Solution {
public:
    int compareAlien(string& s1,string& s2,unordered_map<char,int>& mmap){
        //s2 should be greater than s1
        /*if(s2.length()<s1.length()){
            return -1;
        }*/
        int i = 0;
        while(i<s2.length()&&i<s1.length()&&mmap[s2[i]]==mmap[s1[i]]){
            i++;
        }
        return mmap[s2[i]]-mmap[s1[i]];
    }
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> mmap;
        for(int i=0;i<order.length();++i){
            mmap[order[i]] = i;
        }
        for(int i=1;i<words.size();++i){
            if(compareAlien(words[i-1],words[i],mmap)<0){
                return false;
            }
        }
        return true;
    }
};
