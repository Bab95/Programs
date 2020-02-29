class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<int> tmp(n,0);
        vector<vector<int> > matrix(n);
        for(int i=0;i<n;i++){
            matrix[i] = tmp;
        }
        int index = 1;
        int min_i = 1;
        int min_j = 0;
        int max_i = n-1;
        int max_j = n-1;
        int i = 0;
        int j = 0;
        int direction = 0;
        while(index<=n*n){
            matrix[i][j] = index++;
            if(direction==0){
                if(j==max_j){
                    i++;
                    direction = 1;
                    max_j--;
                }else{
                    j++;
                }
            }else if(direction==1){
                if(i==max_i){
                    direction = 2;
                    max_i--;
                    j--;
                }else{
                    i++;
                }
            }else if(direction==2){
                if(j==min_j){
                    direction = 3;
                    min_j++;
                    i--;
                }else{
                    j--;
                }
            }else if(direction==3){
                if(i==min_i){
                    j = min_j;
                    direction = 0;
                    min_i++;
                }else{
                    i--;
                }
            }
        }
        return matrix;
    }
};
