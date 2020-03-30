#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int m,n;
	    cin>>m>>n;
	    vector<int> arr(m);
	    vector<int> brr(n);
	    for(int i=0;i<m;i++){
	        cin>>arr[i];
	    }
	    for(int j=0;j<n;j++){
	        cin>>brr[j];
	    }
	    vector<int> tmp;
	    map<int,int> my_map;
	    for(int i=0;i<n;i++){
	        my_map[brr[i]] = i;
	    }
	    vector<int> count_array(n,0);
	    for(int i=0;i<m;i++){
	        if(my_map.find(arr[i])!=my_map.end()){
	           count_array[my_map[arr[i]]]++;
	        }else{
	            tmp.push_back(arr[i]);
	        }
	    }
	    /*map<int,int>::iterator itr;
	    for(itr=my_map.begin();itr!=my_map.end();itr++){
	        int val = itr->first;
	        int count = itr->second;
	        while(count--){
	            cout<<val<<" ";
	        }
	    }*/
	    for(int i=0;i<n;i++){
	        int count = count_array[i];
	        while(count--){
	            cout<<brr[i]<<" ";
	        }
	    }
	    if(tmp.size()!=0){
	        sort(tmp.begin(),tmp.end());
	        for(int i=0;i<tmp.size();i++){
	            cout<<tmp[i]<<" ";
	        }
	    }
	    cout<<endl;
	}
	return 0;
}
