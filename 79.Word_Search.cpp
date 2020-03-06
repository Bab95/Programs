class Solution {
public:
    bool issafe(int i,int j,vector<vector<char> >& board,vector<vector<bool> >& visited){
        //cout<<"insafe ";
        if(i>=0&&i<board.size()&&j>=0&&j<board[0].size()&&!visited[i][j]){
            //cout<<"returning true"<<endl;
            return true;
        }
        //cout<<"returning false "<<endl;
        return false;
    }
    bool dfs(vector<vector<char> >& board,vector<vector<bool> >& visited,int i,int j,int index,string word){
        /*if(i<0||i>=board.size()||j<0||j>=board[0].size()||board[i][j]!=word[index]){
            return false;
        }*/
        visited[i][j] = true;
        //cout<<board[i][j]<<" "<<i<<" "<<j<<endl;
        if(index==word.length()-1&&board[i][j]==word[index]){
            return true;
        }
        int row[]={-1,1,0,0};
        int col[]={0,0,-1,1};
        for(int k=0;k<4;k++){
            //cout<<k<<" ";
            if(issafe(i+row[k],j+col[k],board,visited)&&board[i+row[k]][j+col[k]]==word[index+1]){
                if(dfs(board,visited,i+row[k],j+col[k],index+1,word)){
                    return true;
                }
            }
        }
        visited[i][j] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size()==0||board[0].size()==0||word.length()==0){
            return false;
        }
        //vector<bool> tmp(false,board[0].size());
        vector<vector<bool> > visited(board.size(),vector<bool>(board[0].size(),false));

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    int index = 0;
                    bool res = dfs(board,visited,i,j,index,word);
                    if(res==true){
                        return true;
                    }
                }
            }
        }
        /*for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                cout<<visited[i][j]<<" ";
            }
            cout<<endl;
        }*/
        return false;
    }
};
