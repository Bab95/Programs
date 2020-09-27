vector<int> Solution::nextPermutation(vector<int> &A) {
    int index = A.size()-1;
    while(index>0&&A[index]<A[index-1]){
        index--;
    }
    if(index==0){
        int l = 0;
        int r = A.size()-1;
        while(l<r){
            swap(A[l],A[r]);
            ++l;
            --r;
        }
        return A;
    }
    int current = A[index-1];
    int diff = abs(A[index]-current);
    int p = index;
    for(int j=index+1;j<A.size();++j){
        if(A[j]>current&&abs(A[j]-current)<diff){
            p = j;
            diff = abs(A[j]-current);
        }
    }
    swap(A[index-1],A[p]);
    int l = index;
    int r = A.size()-1;
    while(l<r){
        swap(A[l],A[r]);
        ++l;
        --r;
    }
    return A;
}
