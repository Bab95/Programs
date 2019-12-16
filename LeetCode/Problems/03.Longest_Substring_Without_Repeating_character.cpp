#define NO_OF_CHAR 256
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0){
            return 0;
        }
        int visited_last[NO_OF_CHAR];
        for(int i=0;i<NO_OF_CHAR;i++){
            visited_last[i] = -1;
        }
        visited_last[s[0]] = 0;
        int current_length = 1;
        int max_length = 1;
        int previous_index;
        for(int i=1;i<s.length();i++){
            previous_index = visited_last[s[i]];
            if(previous_index==-1||i-current_length>previous_index){
                current_length++;
            }else{
                if(max_length<current_length){
                    max_length = current_length;
                }
                current_length = i-previous_index;
            }
            visited_last[s[i]] = i;
        }
        if(current_length>max_length){
            max_length = current_length;
        }
        return max_length;
    }
};
