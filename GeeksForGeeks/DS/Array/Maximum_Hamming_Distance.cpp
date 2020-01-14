#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int max(int a, int b){
	return a > b ? a : b;
}
int main(){
	int t, n;
	freopen("input.txt", "r", stdin);
	cin >> t;
	while (t--){
		cin >> n;
		int *arr = new int[n];
		int *brr = new int[2 * n + 1];
		for (int i = 0; i < n; i++){
			cin >> arr[i];
			brr[i] = arr[i];
			brr[n + i] = arr[i];
		}
		int current = 0;
		int maxdist = -1;
		for (int i = 1; i < n; i++){
			current = 0;
			for (int j = i, k = 0; j < (i + n); j++, k++){
				if (brr[j] != arr[k]){
					current++;
				}
			}
			maxdist = max(current, maxdist);
		}
		cout << maxdist << endl;
	}
	return 0;
}
