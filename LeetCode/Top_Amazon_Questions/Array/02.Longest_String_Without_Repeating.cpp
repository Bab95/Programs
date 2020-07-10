class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0){
            return 0;
        }
        vector<int> last(256,-1);
        last[s[0]] = 0;
        int current_length = 1;
        int max_length = 1;
        for(int i=1;i<s.length();++i){
            if(last[s[i]]==-1){
                current_length++;
            }else{
                if(i-current_length>last[s[i]]){
                    //not part....
                    current_length++;
                }else{
                    max_length = max(max_length,current_length);
                    current_length = i - last[s[i]];
                }
            }
            last[s[i]] = i;
        }
        max_length = max(max_length,current_length);
        return max_length;
    }
};
