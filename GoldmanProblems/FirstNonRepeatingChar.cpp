#include <string>
#include <queue>
#include <iostream>
using namespace std;
#define SIZE 26
void initialize(int arr[],int n,int a){
    for(int i=0;i<n;i++){
        arr[i] = a;
    }
}
int main() {
	//code
	int hash[SIZE];
	int count[SIZE];
	int t;
	int l;
	cin>>t;
	queue<char> q;
	while(t--){
	    cin>>l;
	    string s;
	    cin>>s;
	    initialize(hash,SIZE,-1);
	    initialize(count,SIZE,0);
	    for(int i=0;i<s.length();i++){
	        q.push(s[i]);
	        count[(int)s[i]-97]++;
	    }
	    bool flag = false;
	    while(!q.empty()){
	        char a = q.front();
	        q.pop();
	        if(count[(int)a-97]==1){
	            cout<<a<<endl;
	            flag = true;
	            break;
	        }
	    }
	    if(flag==false){
	        cout<<"-1"<<endl;
	    }
	    while(!q.empty()){
	        q.pop();
	    }
	    //cout<<s<<endl;
	}

	return 0;
}
