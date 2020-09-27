#include <iostream>
#include <vector>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    int current_max,_max =INT_MIN;
    int start = -1;
    current_max = 0;
    start = 0;
    int s = 0;
    int e = 0;
    for(int i=1;i<n;++i){
        current_max+=arr[i];
        if(_max<current_max){
            s = start;
            e = i;
            _max = current_max;
        }
        if(current_max<0){
            current_max = 0;
            start = i+1;
        }
    }
    cout<<"window size::::"<<(e-s+1)<<" "<<"sum is:::::"<<_max<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t-- ){
        solve();
    }
}

/*
1
8
-2 -3 4 -1 -2 1 5 -3
 */
