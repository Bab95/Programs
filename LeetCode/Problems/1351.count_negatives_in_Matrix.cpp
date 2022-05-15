class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int j = grid[0].size()-1;
        int i = 0;
        int count = 0;
        while (i < grid.size() && j >=0){
            if (grid[i][j] < 0){
                int negs = grid.size() - i;
                count += negs;
                j--;
            }else if (grid[i][j] >=0 ){
                i++;
            }
        }
        return count;
    }
};