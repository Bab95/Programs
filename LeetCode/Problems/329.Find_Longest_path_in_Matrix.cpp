class Solution {
public:
    bool safe(int x,int y,vector<vector<int> >& matrix){
        if(x>=0&&x<matrix.size()&&y>=0&&y<matrix[0].size()){
            return true;
        }
        return false;
    }
    int findPath(vector<vector<int> >&matrix,int i,int j,vector<vector<int> >& dist){
        if(dist[i][j]!=0){
            return dist[i][j]; 
        }
        int result = 1;
        static int row[] = {0,0,1,-1};
        static int col[] = {1,-1,0,0};
        for(int k=0;k<4;++k){
            int x = i+row[k];
            int y = j+col[k];
            if(safe(x,y,matrix)&&matrix[x][y]>matrix[i][j]){
                result = max(result,1+findPath(matrix,x,y,dist));
            }
        }
        dist[i][j] = result;
        return result;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size()==0){
            return 0;
        }
        vector<vector<int> > dist(matrix.size(),vector<int>(matrix[0].size(),0));
        int result = 0;
        for(int i=0;i<matrix.size();++i){
            for(int j=0;j<matrix[i].size();++j){
                if(dist[i][j]==0){
                    result = max(result,findPath(matrix,i,j,dist));
                }
            }
        }    
        return result;
    }
};