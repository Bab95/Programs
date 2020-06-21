class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0){
            return false;
        }
        if(matrix[0].size()==0){
            return false;
        }
        int x = 0,y = matrix[0].size()-1;
        while(x<matrix.size()&&y>=0){
            if(target==matrix[x][y]){
                return true;
            }else if(target>matrix[x][y]){
                x++;
            }else if(target<matrix[x][y]){
                y--;
            }
        }
        return false;
    }
};
