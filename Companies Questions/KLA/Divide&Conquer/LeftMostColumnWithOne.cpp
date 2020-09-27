#include<bits/stdc++.h>
using namespace std;
class BinaryMatrix {
    public:
        int get(int row, int col);  
        vector<int> dimensions();
};
class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        const int rows = binaryMatrix.dimensions()[0];
        const int cols = binaryMatrix.dimensions()[1];
        int ans = cols;
        for(int i=0;i<rows;++i){
            int j = ans-1;
            while(j>=0){
                if(binaryMatrix.get(i,j)==0){
                    break;
                }else{
                    ans--;
                    j--;
                }
            }
        }
        if(ans==cols){
            return -1;
        }
        return ans;
    }
};