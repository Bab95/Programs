#include <iostream>
#include <vector>
using namespace std;

int main() {
	//code
	int t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
	    int coin_s = sizeof(coins)/sizeof(int);
	    //int res = 0;
	    vector<int> res;
	    for(int i=coin_s-1;i>=0;i--){
	        while(n>=coins[i]){
	            n = n-coins[i];
	            res.push_back(coins[i]);
	        }
	    }
	    for(int i=0;i<res.size();i++){
	        cout<<res[i]<<" ";
	    }
	    cout<<endl;

	}
	return 0;
}
