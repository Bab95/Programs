#include <iostream>
#include <string>
using namespace std;
int main(){
    string N;
    cin>>N;
    int sum = 0;
    for(int i=0;i<N.length();++i){
        sum += (N[i]-'0');
        sum = sum%9;
    }
    if(sum!=0){
        cout<<"No"<<endl;
    }else{
        cout<<"Yes"<<endl;
    }
}