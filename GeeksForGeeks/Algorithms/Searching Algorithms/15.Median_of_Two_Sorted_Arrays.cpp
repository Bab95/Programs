#include <bits/stdc++.h>
using namespace std;
void input(vector<int>& arr,int n){
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
}
double findMedian(vector<int>& arr,vector<int>& brr){
    if(arr.size()>brr.size()){
        return findMedian(brr,arr);
    }
    int start = 0;
    int end = arr.size();
    while(start<=end){
        int partition = (arr.size()+brr.size()+1)/2;
        int partitionArr = (start+end)/2;
        int partitionBrr = partition - partitionArr;
        int max_left_Arr = (partitionArr==0)?INT_MIN:arr[partitionArr-1];
        int max_left_Brr = (partitionBrr==0)?INT_MIN:brr[partitionBrr-1];
        int min_right_Arr = (partitionArr==arr.size())?INT_MAX:arr[partitionArr];
        int min_right_Brr = (partitionBrr==brr.size())?INT_MAX:brr[partitionBrr];
        if((max_left_Arr<=min_right_Brr)&&(max_left_Brr<=min_right_Arr)){
            //found the point i am looking for...
            double median = -1;
            if((arr.size()+brr.size())%2==0){
                int m1 = max(max_left_Arr,max_left_Brr);
                int m2 = min(min_right_Brr,min_right_Arr);
                median = avg(m1,m2);
                return median;
            }else{
                median = (double)max(max_left_Arr,max_left_Brr);
                return median;
            }
        }else if(max_left_Arr>min_right_Brr){
            end = partitionArr-1;
        }else{
            start = partitionArr + 1;
        }

    }
    return -1;
}
void solve(){
    int m,n;
    cin>>m>>n;
    vector<int> arr(m);
    vector<int> brr(n);
    input(arr,m);
    input(brr,n);
    double median = findMedian(arr,brr);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
