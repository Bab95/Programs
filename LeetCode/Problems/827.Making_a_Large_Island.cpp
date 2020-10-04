class Solution {
public:
    vector<int> dx = {-1,1,0,0};
    vector<int> dy = {0,0,-1,1};
    bool safe(vector<vector<int>>& grid,int x,int y){
        if(x>=0&&x<grid.size()&&y>=0&&y<grid[0].size()){
            return true;
        }
        return false;
    }
    void dfs(vector<vector<int>>& grid,int i,int j,int id,int& count){
        grid[i][j] = id;
        count++;
        for(int k=0;k<4;++k){
            int nx = dx[k] + i;
            int ny = dy[k] + j;
            if(safe(grid,nx,ny)&&grid[nx][ny]==1){
                dfs(grid,nx,ny,id,count);
            }
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        unordered_map<int,int> mmap;
        int id = 2;
        int ans = 0;
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(grid[i][j]==1){
                    int count = 0;
                    dfs(grid,i,j,id,count);
                    ans = max(ans,count);
                    mmap[id] = count;
                    id++;
                }
            }
        }
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(grid[i][j]==0){
                    unordered_set<int> islands;
                    for(int k=0;k<4;++k){
                        int nx = dx[k] + i;
                        int ny = dy[k] + j;
                        if(safe(grid,nx,ny)){
                            islands.insert(grid[nx][ny]);
                        }
                    }
                    int current = 1;
                    for(auto it=islands.begin();it!=islands.end();++it){
                        current += mmap[*it];
                    }
                    ans = max(current,ans);
                }
            }
        }
        return ans;
    }
};
