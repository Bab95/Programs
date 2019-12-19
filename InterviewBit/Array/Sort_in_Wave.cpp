void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int partition(vector<int> &A,int start,int end){
    int i = start+1;
    int pivot = A[start];
    for(int j=start+1;j<=end;j++){
        if(A[j]<pivot){
            swap(&A[i],&A[j]);
            i++;
        }
    }
    swap(&A[start],&A[i-1]);
    return i-1;
}
void quicksort(vector<int> &A,int start,int end){
    if(start<end){
        int pivot = partition(A,start,end);
        quicksort(A,start,pivot-1);
        quicksort(A,pivot+1,end);
    }
}
vector<int> Solution::wave(vector<int> &A) {
    quicksort(A,0,A.size()-1);
    int n = -1;
    /*for(int i=0;i<A.size();i++){
        cout<<A[i]<<" ";
    }*/
    if(A.size()%2==0){
        n = A.size()-1;
    }else{
        n = A.size()-2;
    }
    for(int i=0;i<n;){
        swap(&A[i],&A[i+1]);
        i = i+2;
    }
    return A;
}
