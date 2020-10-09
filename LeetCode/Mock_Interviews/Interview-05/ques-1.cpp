class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        sort(A.begin(),A.end(),[](auto const&a,auto const& b){
            return abs(a)<abs(b);
        });
        for(int i=0;i<A.size();++i){
            A[i] *= A[i];
        }
        return A;
    }
};
