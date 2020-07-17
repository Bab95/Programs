class NumMatrix {
public:
    vector<vector<int> > dp;
    void print(vector<vector<int> >& dp){
        int m = dp.size();
        int n = dp[0].size();
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    NumMatrix(vector<vector<int>>& matrix) {
        if(matrix.size()==0){
            return;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> tmp(n+1,0);
        for(int i=0;i<=m;++i){
            dp.emplace_back(tmp);
        }
        for(int i=0;i<=m;++i){
            for(int j=0;j<=n;++j){
                if(i==0||j==0){
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = dp[i-1][j]+dp[i][j-1] - dp[i-1][j-1] + matrix[i-1][j-1];
            }
        }
        //print(dp);
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = dp[row2+1][col2+1] - dp[row2+1][col1] - dp[row1][col2+1] + dp[row1][col1];
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
