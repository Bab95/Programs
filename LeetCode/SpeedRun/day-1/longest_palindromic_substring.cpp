class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()==0||s.length()==1){
            return s;
        }
        vector<vector<bool> > dp(s.length(),vector<bool>(s.length(),false));
        int start = 0;
        int max_length = 1;
        for(int i=0;i<s.length();++i){
            dp[i][i] = true;
            start = i;
        }
        for(int i=0;i<s.length()-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1] = true;
                start = i;
                max_length = 2;
            }
        }

        for(int k=3;k<=s.length();++k){
            for(int i=0;i<s.length()-k+1;++i){
                int j = i+k-1;
                if(s[i]==s[j]&&dp[i+1][j-1]==true){
                    dp[i][j] = true;
                    if(k>max_length){
                        max_length = k;
                        start = i;
                    }
                }/*else{
                    dp[i][j] = false;
                }*/
            }
        }
        return s.substr(start,max_length);
    }
};
/*

"babad"
"cbbd"
"ac"
"ccc"
"a"

*/
