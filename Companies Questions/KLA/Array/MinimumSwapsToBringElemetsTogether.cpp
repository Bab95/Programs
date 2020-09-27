/*
Solution : [2 pointer]
count no of elements less than equal k
Now count elements in the window of count that are greater than k
for each window find min of such elements 
*/

#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,k;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    cin>>k;
    /*
    find the no of elements need to put together
    */
    int window = 0;
    for(int i=0;i<n;++i){
        if(arr[i]<=k){
            window++;
        }
    }
    //find unwanted elements in initial window....
    int swaps = 0;
    for(int i=0;i<window;++i){
        if(arr[i]>k){
            swaps++;
        }
    }
    int ans = swaps;
    for(int i=0,j=window;j<n;i++,++j){
        if(arr[i]>k){
            swaps--;
        }
        if(arr[j]>k){
            swaps++;
        }
        ans = min(swaps,ans);
    }
    cout<<ans<<endl;
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