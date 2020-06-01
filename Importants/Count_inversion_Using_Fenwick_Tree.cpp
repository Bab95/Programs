#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
int max(int a, int b) {
	return a > b ? a : b;
}
int get_Sum(vector<int>& fenwick_Tree, int i) {
	int sum = 0;
	//i += 1;
	while (i>0) {
		sum += fenwick_Tree[i];
		i -= (i&(-i));
	}
	return sum;
}
void update_Fenwick_Tree(vector<int>& fenwick_Tree, int max_element, int i, int delta) {
	//i+=1;
	while (i <= max_element) {
		fenwick_Tree[i] += delta;
		i += (i&(-i));
	}
}
int get_Inversion_Count(vector<int>& arr) {
	int max_element = arr[0];
	for (int i = 0;i<arr.size();++i) {
		max_element = max(max_element, arr[i]);
	}
	int inv_count = 0;
	vector<int> fenwick_Tree(max_element + 1, 0);
	for (int i = arr.size() - 1;i >= 0;--i) {
		//inversion will be the elements that appearing after that element in the
    //sequence and are smaller than the element....
    //so start from the right side as element apperaing after current elemet will
    //already be present in the fenwick tree......
		inv_count += get_Sum(fenwick_Tree, arr[i] - 1);
		update_Fenwick_Tree(fenwick_Tree, max_element, arr[i], 1);
	}
	return inv_count;
}
int main() {
	int t;
	freopen("input.txt", "r", stdin);
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> arr(n);
		for (int i = 0;i < n;++i) {
			cin >> arr[i];
		}
		int inv_Count = get_Inversion_Count(arr);
		cout << inv_Count << endl;
	}
	return 0;
}
