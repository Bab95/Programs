#include <iostream>
#include<unordered_map>
#include<string>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	string str;
	while(t--){
	    cin>>str;
	    bool b=false;
	    unordered_map<int,int>m;
	    for(int i=0;i<str.length();i++){
	        m[str[i]]++;
	        if(m[str[i]]>1){
	            b=true;
	            cout<<str[i]<<" "<<endl;
	            break;
	        }
	    }
	    if(b==false){
	        cout<<"-1"<<endl;
	    }

	}
	return 0;
}
