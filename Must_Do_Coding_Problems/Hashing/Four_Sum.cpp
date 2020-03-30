#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <set>
using namespace std;
int main() {
	//code
	int t;
	//freopen("input.txt","r",stdin);
	cin>>t;
	while(t--){
	    int n,sum,count=0;
	    cin>>n>>sum;
	    if(n<4){
	        cout<<"-1"<<endl;
	        continue;
	    }
	    vector<int> arr(n,0);
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    sort(arr.begin(),arr.end());
	    set<vector<int> > ans;
	    int i = 0,j=0;
	    for(i=0;i<=n-4;i++){
	        for(j=i+1;j<=n-3;j++){
	            int l = j+1;
	            int r = n-1;
	            int tmp = sum-arr[i]-arr[j];

	            while(l<r){
	                if(arr[l]+arr[r]==tmp){
	                    vector<int> t_vec;
	                    t_vec.push_back(arr[i]);
	                    t_vec.push_back(arr[j]);
	                    t_vec.push_back(arr[l]);
	                    t_vec.push_back(arr[r]);
	                    l++;
	                    r--;
	                    count++;
	                    ans.insert(t_vec);
	                }else if(arr[l]+arr[r]>tmp){
	                    r--;
	                }else{
	                    l++;
	                }
	            }
	        }
	    }
	    if(count==0){
	        cout<<"-1";
	    }else{
	        set<vector<int> >::iterator itr;
	        for(itr=ans.begin();itr!=ans.end();itr++){
	            for(vector<int>::const_iterator i=(*itr).begin();i!=(*itr).end();i++){
	                cout<<*i<<" ";
	            }
	            cout<<"$";
	        }
	    }
	    cout<<endl;
	}
	return 0;
}
