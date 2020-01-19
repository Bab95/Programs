class Solution {
public:
    /*
    int min(int a,int b,int c){
        int tmp = a<b?a:b;
        return tmp<c?tmp:c;
    }*/
    int min(int a,int b){
        return a<b?a:b;
    }
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int> > dp;
        vector<int> tmp(n+1);
        for(int i=0;i<=m;i++){
            dp.push_back(tmp);
        }
        cout<<dp.size()<<" "<<dp[0].size()<<endl;
        //int dp[m+1][n+1];
        for(int i=0;i<=m;i++){
            dp[i][0] = i;
        }
        for(int i=0;i<=n;i++){
            dp[0][i] = i;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
                }
            }
        }
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return dp[m][n];
    }
};
