//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool compare(string x, string y) {
	string xy = x.append(y);
	string yx = y.append(x);
	return xy.compare(yx)>0?1:0;
}
void swap(string &a, string &b) {
	string s = a;
	a = b;
	b = s;
}
int partition(vector<string> &arr, int start, int end) {
	string pivot = arr[start];
	int i = start + 1;
	for (int j = start + 1;j <= end;j++) {
		if (compare(arr[j], pivot)) {
			swap(arr[i], arr[j]);
			i++;
		}
	}
	swap(arr[i - 1], arr[start]);
	return i - 1;
}
void quicksort(vector<string> &arr, int start, int end) {
	if (start<end) {
		int pivot = partition(arr, start, end);
		quicksort(arr, start, pivot - 1);
		quicksort(arr, pivot + 1, end);
	}
}
int main() {
	//code
	int t, n;
	//freopen("input.txt", "r", stdin);
	cin >> t;
	while (t--) {
		cin >> n;
		vector<string> arr;
		string s;
		for (int i = 0;i<n;i++) {
			cin >> s;
			arr.push_back(s);
		}
		quicksort(arr, 0, n - 1);
		for (vector<string>::iterator itr = arr.begin();itr != arr.end();itr++) {
			cout << *itr;
		}
		cout << endl;
	}
	return 0;
}
