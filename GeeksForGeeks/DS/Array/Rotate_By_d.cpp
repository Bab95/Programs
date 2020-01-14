#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void rotate(int arr[], int l, int r){
	while (l < r){
		swap(&arr[l], &arr[r]);
		l++;
		r--;
	}
}
void rotateby(int arr[], int n, int k){
	rotate(arr, 0, n - 1);
	rotate(arr, 0, k - 1);
	rotate(arr, k, n - 1);
}
int main(){
	int t, n, k;
	freopen("input.txt", "r", stdin);
	cin >> t;
	while (t--){
		cin >> n >> k;
		int *arr = new int[n];
		for (int i = 0; i < n; i++){
			cin >> arr[i];
		}
		rotateby(arr, n, k);
		for (int i = 0; i < n; i++){
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
