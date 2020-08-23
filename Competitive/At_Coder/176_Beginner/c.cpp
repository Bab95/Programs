#include <iostream>
#include <string>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    int current = arr[0];
    long int ans = 0;
    for(int i=1;i<n;++i){
        if(arr[i]>current){
            current = arr[i];
        }else{
            ans += (current-arr[i]);
        }
    }
    cout<<ans<<endl;
}