#include <iostream>
#include <vector>
#include <string>
#include <stack>
#define fo(i,l,r) for(int i=l;i<=r;++i)
#define fi(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back
#define po pop_back
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long int ll;
typedef unsigned long long int ulli;
using namespace std;
ll min(ll a,ll b){
		return a<b?a:b;
}
void solve(){
		ll n;
		cin>>n;
		vector<int> arr(n);
		for(int i=0;i<n;++i){
			cin>>arr[i];
		}
    stack<int> stk;
    stack<int> stk2;
		int max_depth = 0;
		int depth = 0;
    int current_balanced = 0;
    int max_depth_index = 0;
    int balanced_start = 0;
    int max_balanced = 0;
		for(int i=0;i<arr.size();i++){
			if(arr[i]==1){
				stk.push(1);
        stk2.push(i);
        depth++;
        if(depth>max_depth){
          max_depth = depth;
          max_depth_index = i+1;
        }
			}else{
        //arr[i] = 2...
        current_balanced = i-stk2.top()+1;
        if(current_balanced>max_balanced){
          max_balanced = current_balanced;
          balanced_start = stk2.top()+1;
        }
        stk.pop();
        stk2.pop();
        depth--;
			}
		}
		cout<<max_depth<<" "<<max_depth_index<<" "<<max_balanced<<" "<<balanced_start<<endl;
}
int main(){
		speed;
		solve();
}
/*( ) ( ( ) ) ( ) ( (  )  (  )  )  (  (  )  (  )  )
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
2 4 6 9
*/
