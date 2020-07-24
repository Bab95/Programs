class Solution {
public:
    bool safe(vector<vector<char> >& board,int x,int y){
        if(x>=0&&x<board.size()&&y>=0&&y<board[0].size()){
            return true;
        }
        return false;
    }
    bool dfs(vector<vector<char> >& board,vector<vector<bool> >& visited,string& str,int index,int i,int j){
        visited[i][j] = true;
        index++;
        if(index==str.length()){
            return true;
        }

        static int dx[] = {-1,1,0,0};
        static int dy[] = {0,0,1,-1};
        bool ans = false;
        for(int k=0;k<4;++k){
            int x = i + dx[k];
            int y = j + dy[k];
            if(safe(board,x,y)&&!visited[x][y]&&board[x][y]==str[index]){
                ans = ans || dfs(board,visited,str,index,x,y);
            }
        }
        visited[i][j] = false;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool> > visited(board.size(),vector<bool>(board[0].size(),false));
        for(int i=0;i<board.size();++i){
            for(int j=0;j<board[0].size();++j){
                if(board[i][j]==word[0]){
                    if(dfs(board,visited,word,0,i,j)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
