#include <string>
#include <string.h>
using namespace std;
#define A_SIZE 26
int main() {
	//code
	int t;
	string s1,s2;
	cin>>t;
	int hash[A_SIZE];
	int hash2[A_SIZE];
	while(t--){
	    cin>>s1>>s2;
	    //cin>>s2;
	    memset(hash2,0,sizeof(hash2));
	    memset(hash,0,sizeof(hash));
	    for(int i=0;i<s1.length();i++){
	        hash[(int)s1[i]-97]++;
	    }
	    for(int i=0;i<s2.length();i++){
	        hash2[(int)s2[i]-97]++;
	    }
	    int i = 0;
	    bool flag = false;
	    for(i=0;i<A_SIZE;i++){
	        if(hash[i]!=hash2[i]){
	            cout<<"NO"<<endl;
	            flag = true;
	            break;
	        }
	    }
	    if(i==A_SIZE&&!flag){
	        cout<<"YES"<<endl;
	    }
	}
	return 0;
}
