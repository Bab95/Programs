#include <iostream>
using namespace std;
bool isvalid(int a){
    if(a>=1&&a<=26){
        return true;
    }
    return false;
}
int solve(char *input,int n){
	int solution[n+1];
	solution[0] = 1;
	solution[1] = 1;
	for (int i = 2; i<=n; i++){
		int prev = (int)input[i - 2]-48;
		int current = (int)input[i-1]-48;
		if (current != 0 && prev == 0){
			solution[i] = solution[i - 1];
		}
		else if (current == 0 && isvalid(prev * 10 + current)){
			solution[i] = solution[i - 2];
		}
		else if (current == 0 && !isvalid(prev * 10 + current)){
			return 0;
		}
		else if (!isvalid(prev * 10 + current)){
			solution[i] = solution[i - 1];
		}
		else{
			solution[i] = solution[i - 1] + solution[i - 2];
		}
	}
	return solution[n];
}

int main() {
	//code
	int t;
	int n;
	cin>>t;
	while(t--){
	    cin>>n;
	    char str[n+1];
	    cin>>str;
	    if(str[0]=='0'){
	        cout<<"0"<<endl;
	        continue;
	    }
	    cout<<solve(str,n)<<endl;
	}
	return 0;
}
