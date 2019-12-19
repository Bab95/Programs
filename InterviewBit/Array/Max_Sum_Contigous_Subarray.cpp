int Solution::maxSubArray(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int n = A.size();
    int M[n];
    for(int i=0;i<n;i++){
        M[i] = 0;
    }

    M[0] = A[0];
    for(int i=1;i<n;i++){
        if(M[i-1]+A[i]>0){
            M[i] = M[i-1]+A[i];
        }else{
            M[i] = 0;
        }
    }
    int max = A[0];
    for(int i=0;i<n;i++){
        if(M[i]>max){
            max = M[i];
        }
    }
    return max;
}
