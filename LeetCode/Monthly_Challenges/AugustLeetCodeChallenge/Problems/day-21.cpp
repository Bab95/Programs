class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int l = 0,r = A.size()-1;
        while(l<r){
            while(l<r&&A[l]%2==0){
                l++;
            }
            while(r>l&&A[r]%2==1){
                r--;
            }
            if(l<r){
                swap(A[l],A[r]);
                ++l;
                --r;
            }

        }
        return A;
    }
};
