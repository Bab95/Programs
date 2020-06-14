#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;
typedef long long int ll;
#define m 1000000000
vector<string> responses;
string lie;
void binary_Search(int low, int high) {

	cout << "DEBUG:::(" << low << "," << high << ")" << endl;
	if (low == high) {
		char ans;
		cout << low << endl;
		cin >> ans;
		if (ans == 'E') {
			exit(0);
		}
		else {
			return;
		}
	}
	if (low < high) {
		ll mid = (high - low) / 2 + low;
		cout << "                                                                         DEBUG: " << "line 13" << endl;
		cout <<"                                                                         "<< mid << endl;
		char ans;
		//cin >> lie;
		//responses.push_back(lie);
		cin >> ans;

		if (ans == 'E') {
			cout << "here." << endl;
			exit(0);
		}
		else if (ans == 'G') {
			char ans2;
			ll mid2 = low + ((mid-1) - low) / 2;
			cout << "                                                                         DEBUG: " << "line 26"<<endl;
			cout <<"                                                                         "<< mid2 << endl;
			//cin >> lie;
			//responses.push_back(lie);
			cin >> ans2;
			if (ans2 == 'E') {
				cout << "here..found: " << endl;
				exit(0);
			}
			else if (ans2 == 'G') {
				binary_Search(mid2 + 1, mid - 1);
				binary_Search(mid + 1, high);
			}
			else if (ans2 == 'L') {
				binary_Search(low, mid2 - 1);
				binary_Search(mid + 1, high);
			}
		}
		else if (ans == 'L') {
			char ans2;
			ll mid3 = mid + (high - (mid+1)) / 2;
			cout << "                                                                         DEBUG: " << "line 47" << endl;
			cout <<"                                                                         "<< mid3 << endl;
			//cin >> lie;
			//responses.push_back(lie);
			cin >> ans2;
			if (ans2 == 'E') {
				cout << "here..." << endl;
				exit(0);
			}
			else if (ans2 == 'G') {
				binary_Search(low, mid - 1);
				binary_Search(mid3 + 1, high);
			}
			else if (ans2 == 'L') {
				binary_Search(low, mid - 1);
				binary_Search(mid + 1, mid3 - 1);
			}
		}
	}
}
int main() {
	ll N;
	cin >> N;
	fflush(stdin);
	ll low = 1;
	ll high = N;
	binary_Search(low, high);
}
