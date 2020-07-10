class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        //rotation around vertical axis.....
        for(int row=0;row<matrix.size();++row){
            int l = 0,r = matrix[row].size()-1;
            while(l<r){
                int tmp = matrix[row][l];
                matrix[row][l] = matrix[row][r];
                matrix[row][r] = tmp;
                l++;
                r--;
            }
        }

        /*for(int i=0;i<matrix.size();++i){
            for(int j=0;j<matrix[0].size();++j){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;*/

        //rotation around anti diagoinal axis.....
        for(int row=0;row<matrix.size()-1;row++){
            for(int col = 0;col<matrix.size()-1-row;++col){
                swap(matrix[row][col],matrix[matrix[0].size()-1-col][matrix.size()-1-row]);
            }
        }
        /*for(int i=0;i<matrix.size();++i){
            for(int j=0;j<matrix[0].size();++j){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }*/
    }
};
