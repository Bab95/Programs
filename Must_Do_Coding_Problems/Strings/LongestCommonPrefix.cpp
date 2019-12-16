#include <iostream>
#include <vector>
#include <string>
using namespace std;
string LCP(string s1, string s2){
	int l1 = s1.length();
	int l2 = s2.length();
	string result;
	for (int i = 0, j = 0; i < l1&&j < l2; i++, j++){
		if (s1[i] != s2[j]){
			break;
		}
		result.push_back(s1[i]);
	}
	return result;
}
string LongestCommonPrefix(vector<string> &s){
	string prefix = s[0];
	for (int i = 1; i < s.size(); i++){
		prefix = LCP(prefix, s[i]);
	}
	return prefix;
}
int main(){
	int t, n;
	//freopen("input.txt", "r", stdin);
	cin >> t;
	while (t--){
		cin >> n;
		vector<string> s;
		string p;
		for (int i = 0; i < n; i++){
			cin >> p;
			s.push_back(p);
		}
	    p = LongestCommonPrefix(s);
		if (p.length() == 0){
			cout << "-1" << endl;
		}
		else{
			cout << p << endl;
		}
	}
	return 0;
}
