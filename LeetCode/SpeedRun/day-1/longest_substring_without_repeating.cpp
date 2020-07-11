class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0){
            return 0;
        }
        vector<int> hash(256,-1);
        int start = 0;
        int len = 0;
        int current_length = 0;
        for(int i=0;i<s.length();++i){
            if(hash[s[i]]==-1||hash[s[i]]<start){
                hash[s[i]] = i;
                current_length++;
            }else{
                len = max(len,i-start);
                start = hash[s[i]] + 1;
                current_length = i-hash[s[i]];
                hash[s[i]] = i;
            }
        }
        len = max(current_length,len);
        return len;
    }
};
