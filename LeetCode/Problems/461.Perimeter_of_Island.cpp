class Solution {
public:
    bool safe(vector<vector<int> >& grid,int i,int j){
        if(i>=0&&i<grid.size()&&j>=0&&j<grid[0].size()&&grid[i][j]==1){
            return true;
        }
        return false;
    }
    void dfs(vector<vector<int> >& grid,vector<vector<bool> >& visited,int i,int j,int& ans){
        static int di[] = {0,0,-1,1};
        static int dj[] = {1,-1,0,0};
        visited[i][j] = true;
        ans += 4;
        for(int k=0;k<4;++k){
            int x = di[k]+i;
            int y = dj[k]+j;
            if(safe(grid,x,y)){
                ans--;
                if(!visited[x][y]){
                    dfs(grid,visited,x,y,ans);
                }
            }
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        vector<vector<bool> > visited(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(!visited[i][j]&&grid[i][j]==1){
                    int ans = 0;
                    dfs(grid,visited,i,j,ans);
                    return ans;
                }
            }
        }
        return 0;

    }
};
