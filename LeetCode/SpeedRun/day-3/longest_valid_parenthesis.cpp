class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.length()<2){
            return 0;
        }
        vector<int> dp(s.length(),0);
        int ans = dp[0];
        for(int i=1;i<s.length();++i){
            if(s[i]=='('){
                dp[i] = 0;
                cout<<"dp["<<i<<"] = 0"<<endl;
            }else{
                //s[i] is closing...
                if(s[i-1]=='('){
                    dp[i] = (i-2>=0)?(dp[i-2] + 2):2;
                    if(i-2>=0)
                        cout<<"dp["<<i<<"] = dp["<<i-2<<"] + 2"<<endl;
                    else
                        cout<<"dp["<<i<<"] = 2"<<endl;

                }else{
                    int index = i-dp[i-1];
                    //cout<<index<<endl;
                    if(index>0&&s[index-1]=='('){
                        dp[i] = dp[i-1] + 2;
                        if(index-2>=0){
                            dp[i] += dp[index-2];
                        }
                        cout<<"dp["<<i<<"] = dp["<<i-1<<"] + dp["<<index-2<<"] + 2"<<endl;
                    }else{

                    }
                }
            }
            //cout<<"           dp["<<i<<"] = "<<dp[i]<<endl;
            ans = max(ans,dp[i]);
        }
        /*for(int i=0;i<s.length();++i){
            cout<<dp[i]<<" ";
        }*/
        return ans;
    }
};
/*
"((()))())"
*/
