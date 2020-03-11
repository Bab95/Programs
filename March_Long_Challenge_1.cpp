//CHPINTU
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <list>
#include <string.h>
using namespace std;
#define fori(i,l,r) for(int i=l;i<=r;i++)
#define ford(i,r,l) for(int i=r;i>=l;i--)
#define pb push_back
#define po pop_back
#define INF 1e9+9
int main(){
	int t;
	int n,m;
	int arr[50+1];
	int f[50];
	int p[50];
	//freopen("chi.txt","r",stdin);
	cin>>t;
	while(t--){
		memset(arr,0,sizeof(arr));
		cin>>n>>m;
		for(int i=0;i<n;i++){
			cin>>f[i];
		}
		int ans = INF;
		for(int i=0;i<n;i++){
			cin>>p[i];
			arr[f[i]]+=p[i];
			//ans = min(arr[f[i]],ans);
		}
		/*int type = 0;
		for(int i=1;i<=m;i++){
		    cout<<arr[i]<<" ";
		}
		cout<<endl;*/
		for(int i=1;i<=m;i++){
			ans = (arr[i]!=0)?min(arr[i],ans):ans;
			/*if(arr[i]!=0&&arr[i]<ans){
			    //ans = min(arr[i],ans);
			    ans = arr[i];
			    type = i;
			}*/
		}
		//cout<<type<<" ";
		cout<<ans<<endl;
	}
	return 0;
}
