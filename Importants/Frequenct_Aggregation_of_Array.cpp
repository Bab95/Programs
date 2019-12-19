#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
	int n;
	freopen("input.txt", "r", stdin);
	cin >> n;
	vector<int> nums(n,0);
	for (int i = 0;i < n;i++) {
		cin >> nums[i];
	}
	vector<int> unique_nums;
	for (int i = 0;i<n;i++) {
		while ((i<n - 1) && nums[i] == nums[i + 1]) {
			i++;
		}
		unique_nums.push_back(nums[i]);

	}
	for (int i = 0;i < unique_nums.size();i++) {
		cout << unique_nums[i] << " ";
	}
	cout << endl;

}
