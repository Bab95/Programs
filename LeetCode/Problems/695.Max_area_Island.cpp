class Solution {
public:
    void dfs(vector<vector<int> >& grid,int i,int j,int& count){
        grid[i][j] = 2;
        static int dx[] = {0,0,1,-1};
        static int dy[] = {1,-1,0,0};
        for(int k=0;k<4;++k){
            int x = i + dx[k];
            int y = j + dy[k];
            if(x>=0&&x<grid.size()&&y>=0&&y<grid[0].size()&&grid[x][y]==1){
                count++;
                dfs(grid,x,y,count);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(grid[i][j]==1){
                    int count = 1;
                    dfs(grid,i,j,count);
                    ans = max(ans,count);
                }
            }
        }
        return ans;
    }
};
