#include <iostream>
#include <string>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	string s;
	while(t--){
	    cin>>s;
	    stack<char> s1,s2;
	    for(int i=0;s[i]!='\0';i++){
	        s1.push(s[i]);
	    }
	    char t;
	    while(!s1.empty()){
	        t = s1.top();
	        s1.pop();
	        if(t=='.'){
	            while(!s2.empty()){
	                cout<<s2.top();
	                s2.pop();
	            }
	            cout<<t;
	            continue;
	        }
	        s2.push(t);
	    }
	    while(!s2.empty()){
	        cout<<s2.top();
	        s2.pop();
	    }
	    cout<<endl;
	}
	return 0;
}
