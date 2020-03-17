class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()==0||s.length()==1){
            return s;
        }
        vector<vector<int> > dp(s.length(),vector<int>(s.length(),0));
        int max_length = INT_MIN;
        int start_index = -1;
        for(int i=1;i<s.length();i++){
            if(s[i]==s[i-1]){
                dp[i-1][i] = 1;
                max_length = 2;
                start_index = i-1;
            }
        }
        for(int i=0;i<s.length();i++){
            dp[i][i] = 1;
        }
        int k;//to keep the length track
        for(int k=3;k<=s.length();k++){
            for(int i=0;i<s.length()-k+1;i++){
                int j = i + k -1;
                if(s[i]==s[j]&&dp[i+1][j-1]==1){
                    dp[i][j] = 1;
                    if(k>max_length){
                        start_index = i;
                        max_length = k;
                    }
                }else{
                    dp[i][j] = 0;
                }
            }
        }
        /*for(int i=0;i<s.length();i++){
            for(int j=0;j<s.length();j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }*/
        if(start_index==-1){
            return s.substr(0,1);
        }
        string result = s.substr(start_index,max_length);
        //cout<<result<<max_length<<endl;
        return result;
    }
};
