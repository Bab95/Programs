#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;
void input(vector<string>& arr,int n){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}
int max(int a,int b){
    return a>b?a:b;
}
int max_substr(string& a,string&b ){
    int i = 0,j = 0;
    while(i<a.length()&&j<b.length()){
        if(a[i]==b[j]){
            i++;
            j++;
        }else{
            i++;
        }
    }
    if(j==b.length()){
        return j;
    }
    return -1;
}
void solve(){
    int n;
    cin>>n;
    vector<string> arr(n);
    input(arr,n);
    string s;
    cin>>s;
    int max_length = -1;
    int max_index = -1;
    for(int i=0;i<n;i++){
        int tmp = max_substr(s,arr[i]);
        if(tmp>max_length){
            max_length = tmp;
            max_index = i;
        }
    }
    if(max_index!=-1){
        cout<<arr[max_index]<<endl;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
