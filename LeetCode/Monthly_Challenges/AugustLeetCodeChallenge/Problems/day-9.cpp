class Solution {
public:
    bool safe(vector<vector<int> >& grid,int i,int j){
        if(i>=0&&i<grid.size()&&j>=0&&j<grid[0].size()&&grid[i][j]==1){
            return true;
        }
        return  false;
    }
    void bfs(vector<vector<int> >& grid,int& time){
        static int dx[] = {-1,1,0,0};
        static int dy[] = {0,0,-1,1};
        queue<pair<int,int> > q;
        int fresh = 0;
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(grid[i][j]==2){
                    q.push({i,j});
                }else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        while(!q.empty() && fresh){
            int n = q.size();
            for(int i=0;i<n;++i){
                auto p = q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int x = p.first + dx[k];
                    int y = p.second + dy[k];
                    if(safe(grid,x,y)){
                        q.push({x,y});
                        grid[x][y] = 3;
                        fresh--;
                    }
                }
            }
            if(q.size()){
                time++;
            }
        }
        if(fresh!=0){
            time = -1;
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;


        bfs(grid,time);
        return time;
    }
};
/*

[1 2 1 1 2 1 1]
*/
