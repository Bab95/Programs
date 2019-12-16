#include <string.h>
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n==0){
            string result = "";
            return result;
        }else if(n==1){
            return s;
        }
        bool dp[n][n];
        memset(dp,false,sizeof(dp));
        for(int i=0;i<n;i++){
            dp[i][i] = true;
        }
        int starting_index = 0;
        int max_length = 1;
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1] = true;
                max_length = 2;
                starting_index = i;
            }
        }
        for(int len=3;len<=n;len++){
            for(int start_index=0;start_index<n-len+1;start_index++){
                int end_index = start_index+len-1;
                if(dp[start_index+1][end_index-1]==true&&s[start_index]==s[end_index]){
                    dp[start_index][end_index] = true;
                    if(len>max_length){
                        max_length = len;
                        starting_index = start_index;
                    }
                }
            }
        }
        string result;
        for(int i=starting_index;i<starting_index+max_length;i++){
            result.push_back(s[i]);
        }
        return result;
    }
};
