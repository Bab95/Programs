// { Driver Code Starts
// C++ program to merge k sorted arrays of size n each
//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
using namespace std;
bool sortinrev(const pair<int, int> &a,
	const pair<int, int> &b)
{
	return (a.first > b.first);
}
int main() {
	//code
	int t;
	//freopen("input.txt", "r", stdin);
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> arr(n);
		for (int i = 0;i<n;i++) {
			cin >> arr[i];
		}
		sort(arr.begin(), arr.end());
		pair<int, int> p;
		vector<int> unique;
		int count = 0;
		vector<pair<int, int> > pairs;
		for (int i = 0;i<n;i++) {
			count = 1;
			while (i<n - 1 && arr[i] == arr[i + 1]) {
				i++;
				count++;

			}

			p.first = count;
			p.second = arr[i];
			pairs.push_back(p);
		}
		sort(pairs.begin(), pairs.end(), sortinrev);
		map<int, vector<int> > my_map;
		int x = pairs.size();
		for (int i = 0;i<x;i++) {
			while (i<x-1&&pairs[i].first == pairs[i + 1].first) {
				my_map[pairs[i].first].push_back(pairs[i].second);
				i++;
			}
			my_map[pairs[i].first].push_back(pairs[i].second);
		}
		for (map<int, vector<int> >::iterator itr = my_map.begin();itr != my_map.end();itr++) {
			sort(itr->second.begin(), itr->second.end());
		}
		for (map<int, vector<int> >::reverse_iterator itr = my_map.rbegin();itr != my_map.rend();itr++) {
			int count = itr->first;
			for (int i = 0;i<itr->second.size();i++) {
				int c = count;
				int val = itr->second[i];
				while (c--) {
					cout << val << " ";
				}
			}
		}
		cout << endl;
	}
	return 0;
}
