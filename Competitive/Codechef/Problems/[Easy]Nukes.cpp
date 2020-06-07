#include <iostream>
#include <vector>
using namespace std;
void print(vector<int>& ans){
    for(int i=0;i<ans.size();++i){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int n,k,a;
    cin>>a>>n>>k;
    vector<int> ans(k,0);
    if(a==0){
        print(ans);
        return 0;
    }
    for(int i=0;i<k;++i){
        ans[i] = a%(n+1);
        a = a/(n+1);
    }
    print(ans);
    return 0;
}
