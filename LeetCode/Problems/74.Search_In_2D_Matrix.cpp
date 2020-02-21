class Solution {
public:
    bool binary_search_row(vector<vector<int> >& matrix,int target,int row,int low,int high){
        if(low<=high){
            int mid = low+(high-low)/2;
            if(matrix[row][mid]==target){
                return true;
            }else if(matrix[row][mid]<target){
                return binary_search_row(matrix,target,row,mid+1,high);
            }else{
                return binary_search_row(matrix,target,row,low,mid-1);
            }
        }
        return false;
    }
    bool binary_search_col(vector<vector<int> >& matrix,int target,int low,int high){
        int n = matrix[0].size();
        if(low<=high){
            int mid = low+(high-low)/2;
            if(matrix[mid][n-1]==target){
                return true;
            }else if(matrix[mid][n-1]>target){
                if(matrix[mid][0]==target){
                    return true;
                }else if(matrix[mid][0]<target){
                    return binary_search_row(matrix,target,mid,0,n-1);
                }else{
                    return binary_search_col(matrix,target,low,mid-1);
                }
            }else if(matrix[mid][n-1]<target){
                return binary_search_col(matrix,target,mid+1,high);
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m==0){
            return false;
        }
        int n = matrix[0].size();
        if(n==0){
            return false;
        }
        bool result = binary_search_col(matrix,target,0,m-1);
        return result;
    }
};
