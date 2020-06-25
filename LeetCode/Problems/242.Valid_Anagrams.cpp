class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        vector<int> hash1(256,0);
        vector<int> hash2(256,0);
        int i = 0;
        while(i<s.length()){
            hash1[s[i]]++;
            hash2[t[i]]++;
            ++i;
        }
        for(int i=0;i<256;++i){
            if(hash1[i]!=hash2[i]){
                return false;
            }
        }
        return true;
    }
};
