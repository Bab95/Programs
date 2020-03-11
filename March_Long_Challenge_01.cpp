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
using namespace std;
#define fori(i,l,r) for(int i=l;i<=r;i++)
#define ford(i,r,l) for(int i=r;i>=l;i--)
#define pb push_back
#define po pop_back
#define INF 1e9+9
/*struct point{
	int x;
	int y;
}*/
void Print(int arr[],int n){
	fori(i,1,n-1){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
inline double compare(double x,int y){
	//cout<<x<<" "<<y<<endl;
	return x-(double)y;
}
int main(){
	int t,n,q;
	//freopen("laser_input.txt","r",stdin);
	cin>>t;
	while(t--){
		cin>>n>>q;
		//cout<<n<<" "<<q<<endl;
		int points[n];
		int slope[n];
		int c[n];
		slope[0] = INF;
		c[0] = INF;
		//struct point points[n];

		for(int i=0;i<n;i++){
			cin>>points[i];
		}
		fori(i,1,n-1){
			slope[i] = points[i]-points[i-1];
			c[i] = -1*slope[i]*(i+1)+points[i];
		}
		//Print(slope,n);
		//Print(c,n);
		int x1,x2,y;
		int res = 0;
		//int quer = 0;
		while(q--){
			//quer++;
			res = 0;
			cin>>x1>>x2>>y;
			fori(i,1,n-1){
				if((i==x2&&y==points[i-1])||((i+1)==x1&&y==points[i])){
					//cout<<quer<<" ";
					//cout<<"("<<i<<","<<points[i-1]<<"), ("<<i+1<<","<<points[i]<<") "<<endl;
					//cout<<"continuing"<<endl;
					continue;
				}
				double _x = (double)(y - c[i]);
				_x = (slope[i]==0)?_x:_x/(double)slope[i];
				//cout<<"("<<i<<","<<points[i-1]<<"), ("<<i+1<<","<<points[i]<<") "<<_x<<endl;
				if(compare(_x,x2)>0||compare(_x, x1)<0){
					continue;
				}
				if(compare(_x, i)>=0&&compare(_x, i+1)<=0){
					//cout<<"not"<<endl;
					//if(compare(_x, x2)!=0&&y!=points[i-1]){
						res++;
					//}
				}

			}
			cout<<res<<endl;
		}
	}
	return 0;
}
