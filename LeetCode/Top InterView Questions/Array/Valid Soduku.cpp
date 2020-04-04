class Solution {
public:
    void initialize(vector<bool>& hash){
        for(int i=0;i<hash.size();i++){
            hash[i] = false;
        }
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bool> hash(10,false);
        for(int starti=0;starti<9;starti=starti+3){
            for(int startj=0;startj<9;startj=startj+3){
                initialize(hash);
                for(int i=starti;i<9&&i<starti+3;i++){
                    for(int j=startj;j<9&&j<startj+3;j++){
                        if(board[i][j]!='.'){
                            if(hash[(int)board[i][j]-48]==false)
                                hash[(int)board[i][j]-48] = true;
                            else{
                                return false;
                            }
                        }
                    }
                }
            }
        }

        for(int row = 0;row<9;row++){
            initialize(hash);
            for(int i=0;i<9;i++){
                if(board[row][i]!='.'){
                    if(hash[(int)board[row][i]-48]==false){
                        hash[(int)board[row][i]-48] = true;
                    }else{
                        return false;
                    }
                }
            }
        }

        for(int col=0;col<9;col++){
            initialize(hash);
            for(int j=0;j<9;j++){
                if(board[j][col]!='.'){
                    if(hash[(int)board[j][col]-48]==false){
                        hash[(int)board[j][col]-48] = true;
                    }else{
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
