class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        bool flag = true;
        vector<int> result;
        for (int j=0;j<n;j++){
            int i = 0;
            int _j = j;
            vector<int> _temp;
            while (_j >= 0 && i < m){
                _temp.push_back(mat[i][_j]);
                _j--;
                i++;
            }
            if (flag){
                reverse(_temp.begin(), _temp.end());
            }
            flag = !flag;
            result.insert(result.end(), _temp.begin(), _temp.end());
        }
        for (int i=1;i<m;i++){
            int j = n-1;
            int _i = i;
            vector<int> _temp;
            while (_i < m && j >= 0){
                _temp.push_back(mat[_i][j]);
                j--;
                _i++;
            }
            if (flag){
                reverse(_temp.begin(), _temp.end());
            }
            flag = !flag;
            result.insert(result.end(), _temp.begin(), _temp.end());
        }
        return result;
    }
};
