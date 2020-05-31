class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        //vector<vector<int> > dp(matrix.size(),vector<int>(matrix[0].size(),0));
        int ans = 0;
        for(int i=0;i<matrix.size();++i){
            ans += matrix[i][0];
        }
        for(int j=1;j<matrix[0].size();++j){
            ans += matrix[0][j];
        }
        for(int i=1;i<matrix.size();++i){
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[i][j]>0){
                    matrix[i][j] = min(matrix[i-1][j-1],min(matrix[i-1][j],matrix[i][j-1]))+1;
                    ans+=matrix[i][j];
                }
            }
        }
        return ans;
    }
};
