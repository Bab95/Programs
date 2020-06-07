#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
/*void to_lower_character(string& s) {
	for (int i = 0;i < s.length();++i) {
		if (s[i] >= 'A'&&s[i] <= 'Z') {
			s[i] = s[i] - 'A' + 'a';
		}
	}
}*/
void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	unordered_map<char, char> mmap;
	mmap['_'] = ' ';

	for (int i = 0;i < s.length();++i) {
		mmap['a' + i] = s[i];
		mmap['A' + i] = s[i] - 'a' + 'A';
	}
	vector<string> sentences(n);
	for (int i = 0;i < n;++i) {
		cin >> sentences[i];
	}
	for(int i=0;i<sentences.size();++i){
	    for(int j=0;j<sentences[i].length();++j){
	        if(mmap.find(sentences[i][j])==mmap.end()){
	            cout<<sentences[i][j];
	        }else{
	            cout<<mmap[sentences[i][j]];
	        }
	    }
	    cout<<endl;
	}
	return;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif // !ONLINE_JUDGE
	solve();
	return 0;
}
