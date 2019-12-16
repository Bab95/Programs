#include <iostream>
#include <string>
using namespace std;
string excelColumn(unsigned long long int num){
    if(num==0){
        return "";
    }
    return excelColumn((num-1)/26)+(char)((num-1)%26+'A');
}
int main() {
	//code
	unsigned long long int num;
	int t;
	cin>>t;
	while(t--){
	    cin>>num;
	    cout<<excelColumn(num)<<endl;
	}
	return 0;
}
