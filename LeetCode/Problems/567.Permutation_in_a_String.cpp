class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> hash2(26,0);
        vector<int> hash1(26,0);
        for(int i=0;i<s1.length();++i){
            hash1[s1[i]-'a']++;
        }
        int start = 0;
        int count = 0;
        for(int i=0;i<s2.length();++i){
            hash2[s2[i]-'a']++;
            if(hash2[s2[i]-'a']<=hash1[s2[i]-'a']){
                count++;
            }
            if(count==s1.length()){
                while(hash2[s2[start]-'a']>hash1[s2[start]-'a']||hash1[s2[start]-'a']==0){
                    if(hash2[s2[start]-'a']>hash1[s2[start]-'a']){
                        hash2[s2[start]-'a']--;
                    }
                    start++;
                }
                if(i-start+1==s1.length()){
                    return true;
                }
            }
        }
        return false;
    }
};
