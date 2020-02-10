class Solution {
public:
    void initialize_hash(int arr[],int size){
        for(int i=0;i<size;i++){
            arr[i] = 0;
        }
    }
    bool isValid(int arr[],int size){
        for(int i=0;i<size;i++){
            if(arr[i]>1){
                return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int hash[10];
        for(int i=0;i<9;i++){
            initialize_hash(hash,10);
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    int index = (int)board[i][j]-48;
                    hash[index]++;
                }
            }
            if(!isValid(hash,10)){
                return false;
            }
        }
        for(int i=0;i<9;i++){
            initialize_hash(hash,10);
            for(int j=0;j<9;j++){
                if(board[j][i]!='.'){
                    int index = (int)board[j][i]-48;
                    hash[index]++;
                }
            }
            if(!isValid(hash,10)){
                return false;
            }
        }
        for(int i=0;i<9;i=i+3){
            for(int j=0;j<9;j=j+3){
                initialize_hash(hash,10);
                /*for(int i=0;i<10;i++){
                    hash[i] = 0;
                }*/
                for(int k=i;k<i+3;k++){
                    for(int l=j;l<j+3;l++){
                        if(board[k][l]!='.'){
                            int index = (int)board[k][l]-48;
                            cout<<k<<" "<<l<<" "<<index<<endl;
                            if(index>0&&index<=9){
                                if(hash[index]!=0){
                                    return false;
                                }else{
                                    hash[index]++;
                                }
                            }else{
                                return false;
                            }
                        }
                    }
                }
                if(!isValid(hash,10)){
                    return false;
                }
            }
        }
        return true;
    }
};
