#include <iostream>
#include <vector>
using namespace std;

int main() {
	//code
	unsigned long long int num;
	int t;
	vector<char> ans;
	cin>>t;
	while(t--){
	    cin>>num;
	    while(num>0){
	        int rem = num%26;
	        if(rem==0){
	            ans.push_back('Z');
	            num = num/26-1;
	        }else{
	            char a = (rem-1)+'A';
	            ans.push_back(a);
	            num = num/26;
	        }
	    }
	    for(auto itr=ans.rbegin();itr!=ans.rend();itr++){
	        cout<<*itr;
	    }
	    ans.clear();
	    cout<<endl;
	}
	return 0;
}
