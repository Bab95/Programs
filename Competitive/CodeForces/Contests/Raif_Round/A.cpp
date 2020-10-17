#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;
void solve(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<abs(b-d)<<endl;
        return;
    }else if(b==d){
        cout<<abs(a-c)<<endl;
        return;
    }
    int ans = abs(a-c) + abs(b-d) + 2;
    cout<<ans<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}