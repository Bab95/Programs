vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int _xor = A[0];
    for(int i=1;i<A.size();++i){
        _xor ^= A[i];
    }
    for(int i=1;i<=A.size();++i){
        _xor ^= i;
    }
    int mask = _xor&(~(_xor-1));
    //cout<<mask<<endl;
    int a = 0;
    int b = 0;
    for(int i=0;i<A.size();++i){
        if(A[i]&mask){
            a ^= A[i];
        }
        else{
            b ^= A[i];
        }
    }
    for(int i=1;i<=A.size();++i){
        if(i&mask){
            a ^= i;
        }else{
            b ^= i;
        }
    }
    int repeated,missing;
    for(int i=0;i<A.size();++i){
        if(a==A[i]){
            repeated = a;
            missing = b;
        }
        if(b==A[i]){
            repeated = b;
            missing = a;
        }
    }
    return {repeated,missing};
}
