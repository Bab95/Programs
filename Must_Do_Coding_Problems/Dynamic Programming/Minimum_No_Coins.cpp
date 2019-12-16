#include <iostream>
int main() {
	int t,n;
	int coins[]={1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
	int c = sizeof(coins)/sizeof(coins[0]);
	cin>>t;
	while(t--){
	    cin>>n;
	    vector<int> values;
	    for(int i=c-1;i>=0;i--){
	        while(n>=coins[i]){
	            values.push_back(coins[i]);
	            n = n-coins[i];
	        }
	    }

	    for(int i=0;i<values.size();i++){
	        cout<<values[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
