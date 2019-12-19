vector<int> Solution::plusOne(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int carry = 0;
    A[A.size()-1] = A[A.size()-1]+1;
    carry = A[A.size()-1]/10;

    if(A[0]==0){
        int i = 0;
        for(i=0;i<A.size()&&A[i]==0;i++);
        //A.pop_back();
        A.erase(A.begin(),A.begin()+i);
    }
    A[A.size()-1] = A[A.size()-1]%10;
    if(carry==0){
        return A;
    }
    for(int i=A.size()-2;i>=0&&carry!=0;i--){
        A[i]+=carry;
        carry = A[i]/10;
        A[i] = A[i]%10;
    }
    if(carry==0){
        return A;
    }
    A.push_back(carry);
    for(int i=0;i<A.size()-1;i++){
        A[i+1] = A[i];
    }
    A[0] = carry;
    return A;
}
