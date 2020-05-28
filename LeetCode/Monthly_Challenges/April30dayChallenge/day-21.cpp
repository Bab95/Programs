/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int binarySearch(BinaryMatrix &binaryMatrix,int low,int high,int ans,int row,int gans){
        if(low>high){
            return ans;
        }
        if(low==high){
            if(binaryMatrix.get(row,low)){
                return low;
            }
            vector<int> dims = binaryMatrix.dimensions();
            if(high<dims[1]-1&&binaryMatrix.get(row,low+1)){
                return low+1;
            }
            return -1;
        }
        int mid = low+(high-low)/2;
        if(binaryMatrix.get(row,mid)){
            return binarySearch(binaryMatrix,low,mid-1,mid,row,gans);
        }
        if(gans!=INT_MAX&&mid>=gans){
            return -1;
        }
        return binarySearch(binaryMatrix,mid+1,high,ans,row,gans);
    }
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dims = binaryMatrix.dimensions();
        int gans = INT_MAX;
        int high = dims[1]-1;
        for(int i=0;i<dims[0];++i){
            //
            int ans = INT_MAX;
            int current = binarySearch(binaryMatrix,0,high,ans,i,gans);
            if(current!=-1&&current<gans){
                gans = current;
            }
        }
        return gans!=INT_MAX?gans:-1;
    }
};
