#include <bits/stdc++.h>
using namespace std;
int solve(){
    int n;
    scanf("%d",&n);
    vector<int> arr(n);
    for(int i=0;i<n;++i){
        scanf("%d",&arr[i]);
    }
    int g = arr[0];
    for(int i=1;i<n;++i){
        g = __gcd(g,arr[i]);
        if(g==1){
            return n;
        }
    }
    return -1;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
}
