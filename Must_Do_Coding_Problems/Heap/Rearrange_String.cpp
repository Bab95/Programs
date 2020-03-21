#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	string s;
	int hash[26];

	while(t--){
	    cin>>s;
	    for(int i=0;i<26;i++){
	        hash[i] = 0;
	    }
	    for(int i=0;i<s.length();i++){
	        hash[s[i]-97]++;
	    }
	    priority_queue<pair<int,char> > pq;
	    for(int i=0;i<26;i++){
	        if(hash[i]==0){
	            continue;
	        }
	        pair<int,char> my_pair;
	        my_pair.first = hash[i];
	        my_pair.second = (char)(i+97);
	        pq.push(my_pair);
	    }
	    string result;
	    pair<int,char> prev;
	    prev.first = -1;
	    prev.second = '$';
	    while(!pq.empty()){
	        pair<int,char> current = pq.top();
	        pq.pop();
	        result.push_back(current.second);
	        current.first--;
	        if(prev.first>0){
	            pq.push(prev);
	        }
	        prev = current;
	    }
	    if(result.length()==s.length()){
	        cout<<1<<endl;
	    }else{
	        cout<<0<<endl;
	    }
	    //cout<<result<<endl;
	}

	return 0;
}
