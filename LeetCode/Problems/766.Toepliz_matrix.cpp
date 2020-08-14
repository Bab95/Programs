class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int digonals = m + n - 1;
        int _i = 0;
        int _j = n-1;
        bool left = true;
        for(int d=0;d<digonals;++d){
            if(_j==-1&&left){
                _i = 1;
                _j = 0;
                left = !left;
            }
            int current = matrix[_i][_j];
            for(int i=_i,j=_j;i<m&&j<n;++i,++j){
                if(matrix[i][j]!=current){
                    return false;
                }
            }
            if(left){
                _j--;
                _i = 0;
            }else{
                _j = 0;
                _i++;
            }
        }
        return true;
    }
};
