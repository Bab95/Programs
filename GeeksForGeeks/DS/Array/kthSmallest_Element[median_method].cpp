#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;
int findMedian(int arr[], int n){
	sort(arr, arr + n);
	return arr[n / 2];
}
void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int partition(int arr[], int l, int r, int x){
	int i;
	for (i = l; i < r; i++){
		if (arr[i] == x){
			break;
		}
	}
	swap(&arr[i], &arr[r]);
	i = l;
	for (int j = l; j < r; j++){
		if (arr[j] <= x){
			swap(&arr[i], &arr[j]);
			i++;
		}
	}
	swap(&arr[i], &arr[r]);
	return i;
}
int kthSmallestElement(int arr[], int l, int r, int k){
	if (k > 0 && k <= r - l + 1){
		int n = r - l + 1;
		int i;
		int *median = new int[(n + 4) / 5];
		for (i = 0; i < n / 5; i++){
			median[i] = findMedian(arr + l + i * 5, 5);
		}
		if (i * 5<n){
			median[i] = findMedian(arr + l + i * 5, n % 5);
			i++;
		}
		int medOfMed = (i == 1) ? median[i - 1] : kthSmallestElement(median, 0, i - 1, i / 2);
		int pivot = partition(arr, l, r, medOfMed);
		if (pivot - l == k - 1){
			return arr[pivot];
		}
		if (pivot - l > k - 1){
			return kthSmallestElement(arr, l, pivot - 1, k);
		}
		return kthSmallestElement(arr, pivot + 1, r, k - (pivot - l + 1));
	}
	return INT_MAX;
}
int main(){
	int t, n, k;
	//freopen("input.txt", "r", stdin);
	cin >> t;
	while (t--){
		cin >> n;
		int *arr = new int[n];
		for (int i = 0; i < n; i++){
			cin >> arr[i];
		}
		cin >> k;
		cout << kthSmallestElement(arr, 0, n - 1, k) << endl;
	}
	return 0;
}
