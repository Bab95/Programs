class Solution {
public:
    void dfs(vector<vector<int>>& grid,int& size,int x,int y,int island_counter){
        size++;
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        grid[x][y] = island_counter;
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 && nx<grid.size() && ny>=0 && ny<grid.size() && grid[nx][ny]==1){
                dfs(grid,size,nx,ny,island_counter);
            }
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        unordered_map<int,int> island_size;
        //vector<vector<bool>> visited(grid.size(),vector<bool>(grid.size(),false));
        int island_counter = 2;
        int max_size = INT_MIN;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    int size = 0;
                    dfs(grid,size,i,j,island_counter);
                    max_size = max(max_size,size);
                    island_size[island_counter++] = size;
                }
            }
        }
        island_size[0] = 0;
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                int current_size = 0;
                if(grid[i][j]==0){
                    for(int k=0;k<4;k++){
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if(nx>=0&&nx<grid.size()&&ny>=0&&ny<grid.size() && island_size[grid[nx][ny]]>0){
                            current_size += island_size[grid[nx][ny]];
                            island_size[grid[nx][ny]] *= (-1);
                        }
                    }
                    for(int k=0;k<4;k++){
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if(nx>=0&&nx<grid.size()&&ny>=0&&ny<grid.size() && island_size[grid[nx][ny]]<0){
                            
                            island_size[grid[nx][ny]] *= (-1);
                        }
                        
                    }
                    current_size += 1;
                    max_size = max(current_size,max_size);
                }
            }
        }
        return max_size;
    }
};