#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;
int findElement(int arr[], vector<vector<int> > queries,int q,int index){
	for (int i = q - 1; i >= 0; i--){
		int left = queries[i][0];
		int right = queries[i][1];
		if (index >= left&&index <= right){
			if (index == left){
				index = right;
			}
			else{
				index--;
			}
		}
	}
	//cout << index << endl;
	return arr[index];
}
int main(){
	int t, n;
	freopen("input.txt", "r", stdin);
	cin >> t;
	while (t--){
		cin >> n;
		int *arr = new int[n];
		for (int i=0; i < n; i++){
			cin >> arr[i];
		}
		vector<vector<int> > queries;
		vector<int> tmp(2);
		int q, index;
		cin >> q >> index;
		for (int i = 0; i < q; i++){
			queries.push_back(tmp);
		}
		for (int i = 0; i < q; i++){
			cin >> queries[i][0] >> queries[i][1];
		}
		cout << findElement(arr, queries,q,index);
	}
	return 0;
}
