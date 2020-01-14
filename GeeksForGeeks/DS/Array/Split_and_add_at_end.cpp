#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int main(){
	int t, n, d;
	freopen("input.txt", "r", stdin);
	cin >> t;
	while (t--){
		cin >> n >> d;
		int *tmp = new int[2 * n];
		int *arr = new int[n];
		for (int i = 0; i < n; i++){
			cin >> tmp[i];
			tmp[i+n] = tmp[i];
		}
		for (int i = d; i < (n + d); i++){
			arr[i - d] = tmp[i];
		}
		for (int i = 0; i < n; i++){
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
