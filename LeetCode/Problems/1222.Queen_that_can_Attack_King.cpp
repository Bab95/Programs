class Solution {
public:
    unordered_map<int,pair<int,int> > directions;
    Solution(){
        directions[0] = {-1,1};
        directions[1] = {0,1};
        directions[2] = {1,1};
        directions[3] = {1,0};
        directions[4] = {1,-1};
        directions[5] = {0,-1};
        directions[6] = {-1,-1};
        directions[7] = {-1,0};
    }
    bool safe(int x,int y){
        if(x>=0&&x<8&&y>=0&&y<8){
            return true;
        }
        return false;
    }
    void bfs(int x,int y,int dir,vector<vector<int>>& board,vector<vector<int> >& ans){
        queue<pair<int,int> > q;
        q.push({x,y});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            if(board[it.first][it.second]){
                ans.push_back({it.first,it.second});
                return;
            }else{
                int n_x = it.first + directions[dir].first;
                int n_y = it.second + directions[dir].second;
                if(safe(n_x,n_y)){
                    q.push({n_x,n_y});
                }
            }
        }
    }
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        set<pair<int,int> > unsafe;
        vector<vector<int> > ans;
        vector<vector<int> > board(8,vector<int>(8,0));
        for(auto it:queens){
            board[it[0]][it[1]] = 1;
        }

        for(int i=0;i<8;++i){
            int n_x = king[0] + directions[i].first;
            int n_y = king[1] + directions[i].second;
            if(!safe(n_x,n_y)){
                continue;
            }
            if(board[n_x][n_y]){
                ans.push_back({n_x,n_y});
            }else{
                bfs(n_x,n_y,i,board,ans);
            }
        }

        return ans;
    }
};
