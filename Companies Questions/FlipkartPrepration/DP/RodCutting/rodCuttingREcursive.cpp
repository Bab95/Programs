#include <bits/stdc++.h>
using namespace std;
int maxRodValue(vector<int>& prices,int len){
    if(len<=0){
        return 0;
    }
    int max_val = INT_MIN;
    for(int i=0;i<len;++i){
        max_val = max(max_val,prices[i]+maxRodValue(prices,len-i-1));
    }
    return max_val;
}
void solve(){
    
    int n;
    cin>>n;
    vector<int> prices(n);
    for(int i=0;i<n;++i){
        cin>>prices[i];
    }
    cout<<maxRodValue(prices,n)<<endl;
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
        solve();
    }
}