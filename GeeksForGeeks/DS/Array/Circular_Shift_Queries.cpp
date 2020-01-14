#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
using namespace std;
void operatequery1(int arr[], int rotation, int *net_rotation,int n){
	*net_rotation = (*net_rotation - rotation)%n;

}
void operatequery2(int arr[], int rotation, int *net_rotation,int n){
	*net_rotation = (*net_rotation + rotation) % n;
}
int operatequery3(int perfix_sum[], int net_rotation, int l, int r,int n){
	l = (l + net_rotation + n) % n;
	r = (r + net_rotation + n) % n;
	int result = 0;
	if (r >= l){
		result = perfix_sum[r+1] - perfix_sum[l];
	}
	else{
		result = perfix_sum[n] - perfix_sum[l];
		result += perfix_sum[r] - perfix_sum[0];
	}
	return result;
}
int main(){
	int t, q, n;
	int type, rot;
	freopen("input.txt", "r", stdin);
	cin >> t;
	while (t--){
		cin >> n;
		int *arr = new int[n];
		int *perfix_sum = new int[n + 1];
		perfix_sum[0] = 0;
		for (int i = 0; i < n; i++){
			cin >> arr[i];
			perfix_sum[i + 1] = perfix_sum[i] + arr[i];
		}
		cin >> q;
		int net_rotation = 0;
		int l, r;
		for (int i = 0; i < q; i++){
			cin >> type;
			switch (type){
			case 1:
				cin >> rot;
				operatequery1(arr, rot, &net_rotation,n);
				break;
			case 2:
				cin >> rot;
				operatequery2(arr, rot, &net_rotation,n);
				break;
			case 3:
				cin >> l >> r;
				cout << operatequery3(perfix_sum, net_rotation, l, r, n) << endl;
				break;
			default:
				break;
			}

		}
	}
	return 0;
}
