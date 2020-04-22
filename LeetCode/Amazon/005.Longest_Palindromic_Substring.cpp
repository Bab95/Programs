class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<int> > dp(s.length(),vector<int>(s.length(),1));

        int max_length = 1;
        pair<int,int> ans;
        for(int i=1;i<s.length();++i){
            if(s[i]==s[i-1]){
                dp[i-1][i] = 2;
                max_length = 2;
                ans.first = i-1;
                ans.second = i;
            }
        }
        int n = s.length();

        for(int k=3;k<=n;k++){
            for(int i=0;i<n-k+1;++i){
                if(s[i]==s[i+k-1]&&(dp[i+1][i+k-2]>1)){
                    dp[i][i+k-1] = max(dp[i+1][i+k-2]+2,dp[i][i+k-1]);
                    if(dp[i][i+k-1]>max_length){
                        max_length = dp[i][i+k-1];
                        ans.first = i;
                        ans.second = i+k-1;
                    }
                }else if(s[i]==s[i+k-1]&&(i+1==i+k-2)){
                    dp[i][i+k-1] = 3;
                    max_length = max(max_length,3);
                    ans.first = i;
                    ans.second = i+k-1;
                }
            }
        }
        cout<<ans.first<<" "<<ans.second<<" "<<max_length<<endl;
        return s.substr(ans.first,max_length);
    }
};
