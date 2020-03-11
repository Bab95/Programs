#include <iostream>
#include <string>
#include <stack>
using namespace std;

string super_reduced_string(string s){
	// Complete this function
	stack<char> st;
	//st.push(s[0]);
	int h=0;
	for(int i=0;i<s.length();i++){
		if(!st.empty()&&st.top()==s[i]){
			st.pop();
			h--;
		}else{
			st.push(s[i]);
			h++;
		}
	}
	if(h==0){
		return "Empty String";
	}
	char t[h+1];
	t[h] = '\0';
	while(!st.empty()){
		t[h-1]=st.top();
		st.pop();
		h--;
	}
	return t;
}

int main() {
	string s;
	cin >> s;
	string result = super_reduced_string(s);
	cout << result << endl;
	return 0;
}
