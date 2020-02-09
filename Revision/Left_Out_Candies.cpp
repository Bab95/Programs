#include <iostream>
using namespace std;
int distribute(int candies,int n){
    int i = 1;
    int result = candies;
    while(candies>0){
        result = candies;
        candies = (candies>=i)?(candies-i):-1;
        i++;
    }
    if(candies==-1){
        return result;
    }
    return 0;
}
int main() {
	//code
	int t,n,m;
	cin>>t;
	while(t--){
	    cin>>n>>m;
	    if(n==1){
	        cout<<"0"<<endl;
	        continue;
	    }
	    int candies = (n*(n+1))/2;
	    if(candies==m){
	        cout<<"0"<<endl;
	    }
	    else if(candies<m){
	        candies = m%candies;
	        cout<<distribute(candies,n)<<endl;
	    }else{
	        int i = 1;
	        int res = m;
	        while(m>0){
	            res = m;
	            m = (m>=i)?m-i:-1;
	            i++;
	        }
	        if(m==-1){
	            cout<<res<<endl;
	        }else{
	            cout<<"0"<<endl;
	        }
	    }
	}
	return 0;
}
