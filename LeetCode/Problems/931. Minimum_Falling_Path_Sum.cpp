#include <limits.h>
class Solution {
public:
    int min(int a,int b,int c){
        int tmp = a<b?a:b;
        return tmp<c?tmp:c;
    }
    int min(int a,int b){
        return a<b?a:b;
    }
    int minFallingPathSum(vector<vector<int>>& A) {
        int n = A.size();
        vector<int> tmp(n);
        vector<vector<int> > dp;
        for(int i=0;i<n;i++){
            dp.push_back(tmp);
        }
        for(int i=0;i<n;i++){
            dp[0][i] = A[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int b = dp[i-1][j];
                int a = (j>=1)?dp[i-1][j-1]:INT_MAX;
                int c = (j==n-1)?INT_MAX:dp[i-1][j+1];
                dp[i][j] = min(a,b,c)+A[i][j];
            }
        }
        int result = dp[n-1][0];
        for(int i=1;i<n;i++){
            result = min(result,dp[n-1][i]);
        }
        return result;
    }
};
