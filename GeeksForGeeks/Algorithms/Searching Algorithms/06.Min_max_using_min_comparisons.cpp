#include <bits/stdc++.h>
using namespace std;
void input(vector<int>& arr,int n){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}
pair<int,int> find(vector<int>& arr,int start,int end){
  pair<int,int> ans,mml,mmr;
  if(start==end){
    ans.first = arr[start];
    ans.second = arr[end];
    return ans;
  }
  if(end==start+1){
    ans.first = min(arr[start],arr[end]);
    ans.second = min(arr[start],arr[end]);
    return ans;
  }
  int mid = (start+end)/2
  mml = find(arr,start,mid);
  mmr = find(arr,mid+1,end);
  ans.first = min(mml.first,mmr.first);
  ans.second = max(mml.second,mmr.second);
  return ans;
}
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    input(arr,n);
    pair<int,int> ans = find(arr,0,n-1);
    cout<<ans.first<<" "<<ans.second<<endl;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    solve();
	}
	return 0;
}
