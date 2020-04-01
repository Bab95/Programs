#include <bits/stdc++.h>
using namespace std;
int main() {
	//code
	int t,n,k;
	cin>>t;
	while(t--){
	    cin>>n;
	    vector<int> arr(n);
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    cin>>k;
	    if(n%2==1){
	        cout<<"False"<<endl;
	        continue;
	    }
	    /*if(n==2){
	        if((arr[0]+arr[1])%k==0){
	            cout<<"True"<<endl;
	        }else{
	            cout<<"False"<<endl;
	        }
	        continue;
	    }*/
	    unordered_map<int,vector<int> > my_map;
	    for(int i=0;i<n;i++){
	        my_map[arr[i]%k].push_back(i);
	    }
	    /*unordered_map<int,vector<int> >::iterator itr;
	    for(itr=my_map.begin();itr!=my_map.end();++itr){
	        cout<<itr->first<<": ";
	        for(vector<int>::iterator i = itr->second.begin();i!=itr->second.end();++i){
	            cout<<*i<<" ";
	        }
	        cout<<endl;
	    }*/
	    vector<int> side1;
	    vector<int> side2;
	    vector<bool> chosen(n,false);
	    for(int i=0;i<n;i++){
	        if(chosen[i]==true){
	            continue;
	        }
	        int modulo = arr[i]%k;
	        int kk = (k-modulo)%k;
	        //cout<<i<<" "<<kk<<endl;
	        if(my_map.find(kk)==my_map.end()){
	            //cout<<"this....";
	            break;
	        }else{
	            side1.push_back(i);
	            chosen[i] = true;
	            bool flag = false;
	            for(vector<int>::iterator j=my_map[kk].begin();j!=my_map[kk].end();j++){
	                if(!chosen[*j]){
	                    chosen[*j] = true;
	                    side2.push_back(*j);
	                    flag = true;
	                    break;
	                }
	            }
	            if(!flag){
	                //cout<<"False"<<endl;
	                break;
	            }
	        }
	    }
	    bool flag = true;
	    for(int i=0;i<n;i++){
	        if(!chosen[i]){
	            //cout<<"this"<<endl;
	           flag = false;
	           break;
             }
        }
        if(!flag){
            cout<<"False"<<endl;
        }else{
            cout<<"True"<<endl;
	    }
	}
	return 0;
}
