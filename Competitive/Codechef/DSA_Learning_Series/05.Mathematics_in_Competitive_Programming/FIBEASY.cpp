#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
typedef long int ll;
typedef unsigned long long int bigint;
int arr[60];
void find_last_digit(){
    arr[0] = 0;
    arr[1] = 1;
    for(int i=2;i<60;++i){
        arr[i] = (arr[i-1] + arr[i-2])%10;
    }
    /*for(int i=0;i<=120;++i){
        if(i==60){
            cout<<endl;
        }
        cout<<arr[i]<<" ";

    }
    cout<<endl;*/
}
void solve(){
    bigint n;
    cin>>n;
    //bigint min_l = (bigint)log2(n);
    //bigint ans_index = (bigint)pow(2,min_l);
    //cout<<ans_index<<endl;
    //bigint index = (ans_index-1)%60;
    bigint x = 1;
    while(x*2<=n){
        x *= 2;
    }
    bigint index = (x-1)%60;
    cout<<arr[index]<<endl;
}
int main(){
    int t;
    cin>>t;
    find_last_digit();
    while(t--){
        solve();
    }
}
