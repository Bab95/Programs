class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.length()<=1){
            return 0;
        }
        int n = s.length();
        vector<int> dp(n,0);
        int ans = 0;
        for(int i=1;i<n;++i){
            if(s[i]==')'){
                if(s[i-1]=='('){
                    dp[i] = (i-2>=0)?(dp[i-2]+2):2;
                }else{
                    if(i-dp[i-1]-1>=0&&s[i-dp[i-1]-1]=='('){
                        dp[i] = dp[i-1] + 2;
                        int prev = (i-dp[i-1]-2>=0)?(dp[i-dp[i-1]-2]):0;
                        dp[i] += prev;
                    }
                }
            }
            ans = max(ans,dp[i]);
        }
        for(int i=0;i<n;++i){
            cout<<dp[i]<<" ";
        }
        return ans;
    }
};
