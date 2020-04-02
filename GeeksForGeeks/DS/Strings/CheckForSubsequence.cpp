#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    string s1,s2;
	    cin>>s2;
	    cin>>s1;
	    int i = 0,j = 0;
	    while(i<s1.length()&&j<s2.length()){
	        if(s1[i]==s2[j]){
	            i++;
	            j++;
	        }else{
	            i++;
	        }
	    }
	    if(j==s2.length()){
	        cout<<1<<endl;
	    }else{
	        cout<<0<<endl;
	    }
	}
	return 0;
}
