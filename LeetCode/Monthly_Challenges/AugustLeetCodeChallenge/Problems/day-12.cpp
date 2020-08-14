class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int> > mat(rowIndex+1,vector<int>());
        mat[0].push_back(1);
        for(int i=1;i<=rowIndex;++i){
            mat[i].push_back(1);
            for(int j=1;j<i;++j){
                mat[i].push_back(mat[i-1][j-1]+mat[i-1][j]);
            }
            mat[i].push_back(1);
        }
        return mat[rowIndex];
    }
};
