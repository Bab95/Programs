class number{
    int num;
    number(){
        this.num = 0;
    }
}
class Solution {
    public boolean safe(int[][] grid,int x,int y){
        return x >= 0 && x < grid.length && y >= 0 && y < grid[0].length;
    }
    public void dfs(int[][] grid,int i,int j,number count,int id){
        count.num++;
        grid[i][j] = id;
        int[] dx = {-1,1,0,0};
        int[] dy = {0,0,-1,1};
        for(int k=0;k<4;++k){
            int nx = dx[k] + i;
            int ny = dy[k] + j;
            if(safe(grid, nx, ny) &&grid[nx][ny]==1){
                dfs(grid,nx,ny,count,id);
            }
        }
    }
    public int max(int a,int b){
        return a>b?a:b;
    }
    public int largestIsland(int[][] grid) {
        int[] dx = {-1,1,0,0};
        int[] dy = {0,0,-1,1};
        number count = new number();
        int id = 2;
        HashMap<Integer,Integer> mmap = new HashMap<Integer,Integer>();
        int ans = 0;
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[0].length;j++){
                if(grid[i][j]==1){
                    count.num = 0;
                    dfs(grid,i,j,count,id);
                    mmap.put(id,count.num);
                    ans = max(ans,count.num);
                    id++;
                }
            }
        }

        for(int i=0;i<grid.length;++i){
            for(int j=0;j<grid[0].length;++j){
                if(grid[i][j]==0){

                    HashSet<Integer> islands = new HashSet<Integer>();
                    for(int k=0;k<4;k++){
                        int nx = dx[k] + i;
                        int ny = dy[k] + j;
                        if(safe(grid, nx, ny) &&grid[nx][ny]!=0){
                            islands.add(grid[nx][ny]);
                        }
                    }
                    int current = 1;
                    for(Integer itr : islands){
                        current += mmap.get(itr);
                    }
                    ans = max(ans,current);
                }
            }
        }
        return ans;
    }
}
