vector<int> Solution::findPerm(const string A, int B) {
    vector<int> ans(B,0);
    for(int i=1;i<=B;++i){
        ans[i-1] = i;
    }
    int i = 0,j=0;
    for(int k=1;k<=A.length();){
        if(A[k-1]=='D'){
            i = k-1;
            j = k;
            while(j<A.length()&&A[j]=='D'){
                j++;
            }
            k = j+1;
            while(i<j){
                swap(ans[i],ans[j]);
                ++i;
                --j;
            }
        }else{
            k++;
        }
    }
    return ans;
}
