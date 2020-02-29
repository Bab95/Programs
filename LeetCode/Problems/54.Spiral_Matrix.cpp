class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m==0){
            vector<int> result;
            return result;
        }
        int n = matrix[0].size();
        int min_i,min_j,max_i,max_j,i,j;
        int index = 0;
        min_i = 1;
        min_j = 0;
        max_i = m-1;
        max_j = n-1;
        int direction = 0;
        i = 0;
        j = 0;
        vector<int> result(m*n);
        while(index<m*n){
            result[index++] = matrix[i][j];
            if(direction==0){
                if(j==max_j){
                    direction = 1;
                    i++;
                    max_j--;
                }else{
                    j++;
                }
            }else if(direction==1){
                if(i==max_i){
                    j--;
                    direction = 2;
                    max_i--;
                }else{
                    i++;
                }
            }else if(direction==2){
                if(j==min_j){
                    i--;
                    direction = 3;
                    min_j++;
                }else{
                    j--;
                }
            }else{
                if(i==min_i){
                    direction = 0;
                    j = min_j;
                    min_i++;
                }else{
                    i--;
                }
            }

        }
        return result;
    }
};
