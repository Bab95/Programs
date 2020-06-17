class Solution {
public:
    void print(vector<vector<char> >& board){
        for(int i=0;i<board.size();++i){
            for(int j=0;j<board[0].size();++j){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    bool safe(int i,int j,vector<vector<char> >& board){
        if(i>=0&&i<board.size()&&j>=0&&j<board[0].size()){
            return true;
        }
        return false;
    }
    void dfs(vector<pair<int,int> >& region,vector<vector<char> >& board,int i,int j,vector<vector<bool> >& visited){
        static int dx[] = {0,0,1,-1};
        static int dy[] = {1,-1,0,0};
        visited[i][j] = true;
        if(!safe(i,j,board)){
            return;
        }
        for(int k=0;k<4;++k){
            int x = i+dx[k];
            int y = j+dy[k];
            if(safe(x,y,board)&&!visited[x][y]&&board[x][y]=='O'){
                region.push_back(make_pair(x,y));
                dfs(region,board,x,y,visited);
            }
        }
    }
    bool boundary(vector<pair<int,int> >& region,vector<vector<char> >& board){
        for(auto p : region){
            if(p.first==board.size()-1||p.second==board[0].size()-1||p.first==0||p.second==0){
                return true;
            }
        }
        return false;
    }
    void covert(vector<vector<char> >& board,vector<pair<int,int> >& region){
        for(auto it : region){
            board[it.first][it.second] = 'X';
        }
    }
    void solve(vector<vector<char>>& board) {
        //print(board);

        if(board.size()==0){
            return;
        }

        vector<vector<pair<int,int> > > regions;

        vector<vector<bool> > visited(board.size(),vector<bool>(board[0].size(),false));

        vector<pair<int,int> > region;

        for(int i=0;i<board.size();++i){
            for(int j=0;j<board[0].size();++j){
                if(!visited[i][j]&&board[i][j]=='O'){
                    region.clear();
                    region.push_back(make_pair(i,j));
                    dfs(region,board,i,j,visited);
                    regions.push_back(region);
                }
            }
        }

        for(auto it : regions){
            /*cout<<"regions--->"<<endl;
            for(int i=0;i<it.size();++i){
                cout<<it[i].first<<" "<<it[i].second<<endl;
            }*/
            if(!boundary(it,board)){
                covert(board,it);
            }
        }
        //cout<<"------ans-------"<<endl;
        //print(board);
    }
};
