class Solution {
public:
    bool safe(int i,int j, vector<vector<char>>& board){
        if (i >=0 && i < board.size() && j >= 0 && j < board[0].size() && board[i][j] == 'X'){
            return true;
        }
        return false;
    }
    bool leftright(vector<vector<char>>& board, int i, int j) {
        bool flag = false;
        board[i][j] = '.';
        int _j = j-1;
        while (safe(i, _j, board)){
            board[i][_j] = '.';
            flag = true;
            _j--;
        }
        _j = j+1;
        while (safe(i, _j, board)){
            board[i][_j] = '.';
            flag = true;
            _j++;
        }
        return flag;
    }
    bool updown(vector<vector<char>>& board, int i, int j){
        int _i = i-1;
        board[i][j] = '.';
        bool flag = false;
        while (safe(_i, j, board)){
            board[_i][j] = '.';
            flag = true;
            _i--;
        }
        _i = i+1;
        while (safe(_i, j, board)){
            board[_i][j] = '.';
            flag = true;
            _i++;
        }
        return flag;
    }
    int countBattleships(vector<vector<char>>& board) {
        int count = 0;
        for (int i=0;i<board.size();i++){
            for (int j=0;j<board[0].size();j++){
                if (board[i][j] == 'X'){

                    if (!leftright(board, i, j)){
                        //cout <<"here";
                        updown(board, i, j);
                    }
                    count++;
                }
            }
        }
        /*
        for (int i=0;i<board.size();i++){
            for (int j=0;j<board[0].size();j++){
                cout << board[i][j] <<" ";
            }
            cout << endl;
        }*/
        return count;
    }
};
