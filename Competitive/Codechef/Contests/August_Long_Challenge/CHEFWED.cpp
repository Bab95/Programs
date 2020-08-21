/*20-Points*/
#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    vector<unordered_set<int> > sset(1,unordered_set<int>());
    int cost = k;
    unordered_set<int> tmp;
    int index = 0;
    int i = 0;
    while(i<n){
        if(sset[index].find(arr[i])==sset[index].end()){
            sset[index].insert(arr[i]);
        }else{
            sset.push_back(tmp);
            index++;
            sset[index].insert(arr[i]);
            cost += k;
        }
        i++;
    }
    cout<<cost<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
