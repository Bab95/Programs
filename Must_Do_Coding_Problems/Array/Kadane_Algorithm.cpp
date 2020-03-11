#include <iostream>
#include <limits.h>
using namespace std;
int max(int a,int b){
    return a>b?a:b;
}
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int current_max = arr[0];
        int max_sum = arr[0];
        for(int i=1;i<n;i++){
            current_max = max(arr[i],current_max+arr[i]);
            max_sum = max(max_sum,current_max);
        }
        cout<<max_sum<<endl;
    }
}
