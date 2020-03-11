#include <iostream>
using namespace std;
int main(){
    int t,n,sum;
    cin>>t;
    while(t--){
        cin>>n>>sum;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int current_sum = 0;
        int start = 0;
        int end = 0;
        while(true){
            if(current_sum==sum){
                cout<<start+1<<" "<<end<<endl;
                break;
            }else if(current_sum<sum){
                if(end==n){
                    cout<<-1<<endl;
                    break;
                }
                current_sum = current_sum+arr[end];
                end++;
            }else{
                if(start==end){
                    cout<<-1<<endl;
                    break;
                }
                current_sum = current_sum-arr[start];
                start++;
            }
        }
    }
}
