class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > result;
        if(numRows==0){
            return result;
        }
        vector<int> tmp;
        tmp.push_back(1);
        result.push_back(tmp);
        for(int i=1;i<numRows;i++){
            vector<int> subres;
            for(int j=0;j<i+1;j++){
                int tmp_val = (j==0||j==i)?1:(result[i-1][j-1]+result[i-1][j]);
                subres.push_back(tmp_val);
            }
            result.push_back(subres);
        }
        return result;
    }
};
