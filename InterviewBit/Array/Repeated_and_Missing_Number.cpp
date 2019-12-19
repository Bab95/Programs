int mod(long long int x){
    if(x>0)
        return x;
    return -1*x;
}
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int xor1 = 0;
    for (int i = 0;i < A.size();i++) {
        xor1 ^= A[i];
    }
    for (int i = 1;i <= A.size();i++) {
        xor1 ^= i;
    }
    int a = 0;
    int b = 0;
    int setbit = xor1&~(xor1 - 1);
    for (int i = 0;i < A.size();i++) {
        if (A[i] & setbit) {
            a ^= A[i];
        }
        else {
            b ^= A[i];
        }
    }
    for (int i = 1;i <= A.size();i++) {
        if (i&setbit) {
            a ^= i;
        }
        else {
            b ^= i;
        }
    }
    vector<int> result;
    //int min = a < b ? a : b;
    //int max = b > a ? b : a;
    //a = min;
    //b = max;
    int repeated = 0;
    int missing = 0;
    for(int i=0;i<A.size();i++){
        if(a==A[i]){
            repeated = a;
            missing = b;
            break;
        }else if(b==A[i]){
            repeated = b;
            missing = a;
            break;
        }
    }
    result.push_back(repeated);
    result.push_back(missing);
    return result;
    return result;

}
