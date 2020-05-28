class Solution {
public:
    bool isSafe(vector<vector<char>>& grid,int i,int j){
        if(i>=0&&i<grid.size()&&j>=0&&j<grid[0].size()&&grid[i][j]=='1'){
            return true;
        }
        return false;
    }
    void dfs(vector<vector<char> >& grid,int i,int j){
        grid[i][j] = '2';
        static int dx[] = {0,-1,0,1,0};
        for(int p=0;p<4;++p){
            if(isSafe(grid,i+dx[p],j+dx[p+1])){
                dfs(grid,i+dx[p],j+dx[p+1]);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                    ++result;
                }
            }
        }
        return result;
    }
};
