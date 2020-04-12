class Solution {
public:
    bool safe(int x,int y,vector<vector<int> >& grid){
        if(x>=0&&x<grid.size()&&y>=0&&y<grid[0].size()&&grid[x][y]==1){
            return true;
        }
        return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int> > q;
        pair<int,int> p;
        int fresh = 0;
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(grid[i][j]==2){
                    p.first = i;
                    p.second = j;
                    q.push(p);
                }else if(grid[i][j]==1){
                    ++fresh;
                }
            }
        }
        int time = 0;
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};
        while(!q.empty()&&fresh!=0){
            int n = q.size();
            ++time;
            for(int i=0;i<n;++i){
                //cout<<q.front().first<<" "<<q.front().second<<" ,";
                pair<int,int> current = q.front();
                q.pop();
                for(int k=0;k<4;++k){
                    if(safe(current.first+dx[k],current.second+dy[k],grid)){
                        pair<int,int> new_pair;
                        new_pair.first = current.first + dx[k];
                        new_pair.second = current.second + dy[k];
                        grid[new_pair.first][new_pair.second] = 2;
                        q.push(new_pair);
                        --fresh;
                    }
                }
            }

        }

        if(fresh!=0){
            return -1;
        }
        return time;
    }
};
