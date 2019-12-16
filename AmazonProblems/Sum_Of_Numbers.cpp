#include <iostream>
#include <string>
using namespace std;

int main() {
	//code
	int t;
	//freopen("input.txt", "r", stdin);
	cin >> t;
	string s;
	while (t--){
		cin >> s;
		int len = s.length();
		int number = 0;
		int sum = 0;
		for (int i = 0; i <= len; i++){
			if ((int)s[i] - 48 >= 0 && (int)s[i] - 48 <= 9){
				number = number * 10 + (int)s[i] - 48;
			}
			else{
				sum += number;
				number = 0;
			}
		}
		cout << sum << endl;
	}
	//system("pause");
	return 0;
}
