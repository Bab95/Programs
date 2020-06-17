class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        if(moves.size()<5){
            return "Pending";
        }
        vector<vector<char> > mat(3,vector<char>(3,'0'));
        int turn = 0;
        for(auto it : moves){
            mat[it[0]][it[1]] = (turn%2==0)?'A':'B';
            turn++;
        }

        string result;
        //corners...
        if(mat[0][0]==mat[1][1]&&mat[1][1]==mat[2][2]){
            if(mat[0][0]!='0'){
                result.push_back(mat[0][0]);
                return result;
            }
        }
        else if(mat[0][2]==mat[1][1]&&mat[1][1]==mat[2][0]){
            if(mat[0][2]!='0'){
                result.push_back(mat[0][2]);
                return result;
            }
        }
        for(int i=0;i<3;++i){
            if(mat[i][0]==mat[i][1]&&mat[i][1]==mat[i][2]){
                if(mat[i][0]!='0'){
                    result.push_back(mat[i][0]);
                    return result;
                }
            }
            if(mat[0][i]==mat[1][i]&&mat[1][i]==mat[2][i]){
                if(mat[0][i]!='0'){
                    result.push_back(mat[0][i]);
                    return result;
                }
            }
        }
        for(int i=0;i<3;++i){
            for(int j=0;j<3;++j){
                if(mat[i][j]=='0'){
                    return "Pending";
                }
            }
        }
        return "Draw";
    }
};
