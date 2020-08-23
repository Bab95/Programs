class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        const int MAX = m*n;
        vector<vector<int> > ans(m,vector<int>(n,0));
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(matrix[i][j]==0){
                    continue;
                }
                else{
                    int up = (i>0)?ans[i-1][j]:MAX;
                    int left = (j>0)?ans[i][j-1]:MAX;
                    ans[i][j] = min(left,up) + 1;
                }
            }
        }
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(matrix[i][j]==0){
                    continue;
                }else{
                    int right = (j<n-1)?ans[i][j+1]:MAX;
                    int down = (i<m-1)?ans[i+1][j]:MAX;
                    int current = min(right,down) + 1;
                    ans[i][j] = min(current,ans[i][j]);
                }
            }
        }
        return ans;
    }
};
