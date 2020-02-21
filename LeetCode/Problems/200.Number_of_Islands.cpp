class Solution {
public:
    bool issafe(int x,int y,vector<vector<char> >& grid){
        int rows = grid.size();
        int cols = grid[0].size();
        if(x>=0&&x<rows&&y>=0&&y<cols&&grid[x][y]=='1'){
            return true;
        }
        return false;
    }
    void dfs(vector<vector<bool> >& visited,int row,int col,vector<vector<char> >& grid){
        int dx[] = {0,0,-1,1};
        int dy[] = {-1,1,0,0};
        visited[row][col] = true;
        for(int i=0;i<4;i++){
            if(issafe(row+dx[i],col+dy[i],grid)&&!visited[row+dx[i]][col+dy[i]]){
                dfs(visited,row+dx[i],col+dy[i],grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if(m==0){
            return 0;
        }
        vector<vector<bool> > visited;
        int n = grid[0].size();
        if(n==0){
            return 0;
        }
        vector<bool> tmp(n,false);
        for(int i=0;i<grid.size();i++){
            visited.push_back(tmp);
        }
        int result = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!visited[i][j]&&grid[i][j]=='1'){
                    dfs(visited,i,j,grid);
                    result++;
                }
            }
        }
        return result;
    }
};
