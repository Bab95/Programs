#include <iostream>
#include <vector>
#include <strings.h>
using namespace std;
#define M 1001
bool primes[M];
int min(int i,int j){
    return i<j?i:j;
}
vector<int> sieve(int n){
    vector<int> result(n+1,0);
    result[1] = 1;
    for(int i=2;i*i<=n;i++){
        if(primes[i]==false){
            //result[i] = i;
            for(int j=i*i;j<=n;j+=i){
                primes[j] = true;
                result[j] = (result[j]==0)?i:result[j];
            }
        }
    }
    return result;
}
int main() {
	//code
	int t,n;
	cin>>t;
	while(t--){
	    cin>>n;
	    vector<int> result = sieve(n);
	    for(int i=1;i<=n;i++){
	        if(result[i]==0){
	            cout<<i<<" ";
	        }else{
	            cout<<result[i]<<" ";
	        }
	    }
	    cout<<endl;
	}
	return 0;
}