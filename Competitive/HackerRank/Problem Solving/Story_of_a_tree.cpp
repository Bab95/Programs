#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

void DFS_subtree(int p, int c, vector<int>& counts, unordered_map<int, vector<int> >& connects,
					unordered_map<int, unordered_set<int> >& guesses){

	if (connects.find(p) != connects.end()){
		for (auto i : connects[p]){
			if (i != c){
				if (guesses.find(p) != guesses.end()){
					if (guesses[p].find(i) != guesses[p].end()){
						++counts[p];
					}
				}
				DFS_subtree(i, p, counts, connects, guesses);
				counts[p] += counts[i];
			}
		}
	}

	return;
}


void DFS_full(int p, int c, vector<int>& counts, unordered_map<int, vector<int> >& connects,
					unordered_map<int, unordered_set<int> >& guesses){

	counts[p] = counts[c];
	if (guesses.find(c) != guesses.end()){
		if (guesses[c].find(p) != guesses[c].end()){
			--counts[p];
		}
	}
	if (guesses.find(p) != guesses.end()){
		if (guesses[p].find(c) != guesses[c].end()){
			++counts[p];
		}
	}

	if (connects.find(p) != connects.end()){
		for (auto i : connects[p]){
			if (i != c){
				DFS_full(i, p, counts, connects, guesses);
			}
		}
	}
	return;
}

void solve(int n, int k, unordered_map<int, vector<int> >& connects, unordered_map<int, unordered_set<int> >& guesses){
	vector<int> counts(n, 0);

	DFS_subtree(0, 0, counts, connects, guesses);
	DFS_full(0, 0, counts, connects, guesses);

	int total = 0;
	for (int i = 0; i < n; ++i){
		if (counts[i] >= k){
			++total;
		}
	}

	if (total == 0){
		cout << "0/1" << endl;
		return;
	}
	if (total == n){
		cout << "1/1" << endl;
		return;
	}
	int divisor = gcd(total, n);
	total = total / divisor;
	n = n / divisor;
	cout << total << "/" << n << endl;
	return;

}



int main(){

	int q;
	cin >> q;
	for (int a0 = 0; a0 < q; a0++){
		int n;
		cin >> n;
		unordered_map<int, vector<int> > connects;
		unordered_map<int, unordered_set<int> > guesses;
		for (int a1 = 0; a1 < n - 1; a1++){
			int u;
			int v;
			cin >> u >> v;
			--u;
			--v;
			connects[u].push_back(v);
			connects[v].push_back(u);
		}
		int g;
		int k;
		cin >> g >> k;
		for (int a1 = 0; a1 < g; a1++){
			int u;
			int v;
			cin >> u >> v;
			--u;
			--v;
			guesses[u].insert(v);
		}
		solve(n, k, connects, guesses);
	}
	return 0;

}
