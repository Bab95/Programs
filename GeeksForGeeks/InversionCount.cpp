#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int merge(int arr[], int left, int mid, int right, int temp[]) {
	int i = left, j = mid, k = left;
	int invcount = 0;
	while (i <= mid - 1 && j <= right) {
		if (arr[i] <= arr[j]) {
			temp[k++] = arr[i++];
		}
		else {
			temp[k++] = arr[j++];
			invcount += (mid - i);
		}
	}
	while (i <= mid - 1) {
		temp[k++] = arr[i++];
	}
	while (j <= right) {
		temp[k++] = arr[j++];
	}
	for (int i = left;i <= right;i++) {
		arr[i] = temp[i];
	}
	return invcount;
}
int mergesort(int arr[], int left, int right, int temp[]) {
	int invcount = 0, mid;
	if (right > left) {
		mid = (right + left) / 2;
		invcount = mergesort(arr, left, mid, temp);
		invcount += mergesort(arr, mid + 1, right, temp);
		invcount += merge(arr, left, mid + 1, right, temp);
	}
	return invcount;
}
int inversioncount(int arr[], int n) {
	int *temp = new int[n];
	return mergesort(arr, 0, n - 1, temp);
}
int main() {
	int n;
	freopen("input.txt", "r", stdin);
	cin >> n;
	int *arr = new int[n];
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}
	cout << inversioncount(arr, n);
	system("pause");
}
