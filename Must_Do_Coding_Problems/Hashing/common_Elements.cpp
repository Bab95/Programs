#include <iostream>
#include <vector>
using namespace std;
int min(int a,int b){
    return a<b?a:b;
}
int main() {
	//code
	int t;
	cin>>t;
	int a,b,c;
	while(t--){
	    cin>>a>>b>>c;
	    vector<int> a1(a);
	    vector<int> a2(b);
	    vector<int> a3(c);
	    for(int i=0;i<a;i++){
	        cin>>a1[i];
	    }
	    for(int i=0;i<b;i++){
	        cin>>a2[i];
	    }
	    for(int i=0;i<c;i++){
	        cin>>a3[i];
	    }
	    int i=0,j=0,k=0;
	    vector<int> result;
	    while(i<a&&j<b&&k<c){
	        if(a1[i]==a2[j]&&a1[i]==a3[k]){
	            result.push_back(a1[i]);
	            //cout<<a1[i]<<" ";
	            i++;
	            j++;
	            k++;
	        }
	        else{
	            int m = min(a1[i],min(a2[j],a3[k]));
	            if(m==a1[i]){
	               i++;
	            }
	            if(m==a2[j]){
	               j++;
	            }
	            if(m==a3[k]){
	               k++;
	            }
	        }
	    }
	    if(result.size()==0){
	        cout<<"-1"<<endl;
	        continue;
	    }else{
	        int i = 0;
	        int n = result.size();
	        for(int i=0;i<n;i++){
	            cout<<result[i]<<" ";
	            while(i<n-1&&result[i]==result[i+1]){
	                i++;
	            }

	        }
	        cout<<endl;
	    }

	}
	return 0;
}
