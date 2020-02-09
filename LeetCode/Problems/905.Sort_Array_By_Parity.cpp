class Solution {
public:
    void swap(int *a,int *b){
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
    vector<int> sortArrayByParity(vector<int>& A) {
        int l = 0;
        int r = A.size()-1;
        while(l<r){
            if(A[l]%2==0){
                l++;
            }else{
                swap(&A[l],&A[r]);
                r--;
            }
        }
        return A;
    }
};
