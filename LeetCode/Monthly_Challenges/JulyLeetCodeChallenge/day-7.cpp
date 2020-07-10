class Solution {
public:
    bool safe(vector<vector<int> >& grid,int x,int y){
        if(x>=0&&x<grid.size()&&y>=0&&y<grid[0].size()&&grid[x][y]==1){
            return true;
        }
        return false;
    }
    void dfs(vector<vector<int> >& grid,vector<vector<bool> >& visited,int i,int j,int& ans){
        visited[i][j] = true;
        static int dx[] = {0,0,-1,1};
        static int dy[] = {1,-1,0,0};
        ans += 4;
        for(int k=0;k<4;++k){
            int x = i+dx[k];
            int y = j+dy[k];
            if(safe(grid,x,y)){
                if(!visited[x][y]){
                    dfs(grid,visited,x,y,ans);
                }
                ans -= 1;
            }
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        if(grid.size()==0){
            return 0;
        }
        vector<vector<bool> > visited(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(grid[i][j]==1){
                    int ans = 0;
                    dfs(grid,visited,i,j,ans);
                    return ans;
                }
            }
        }
        return 0;
    }
};
