#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int evens = 0;
    for(int i=0;i<s.length();i++){
        int j = 0;
        while(i<s.length()-1&&s[i]==s[i+1]){
            j++;
            i++;
        }
        if((j+1)%2==0){
            evens++;
        }
    }
    cout<<evens<<endl;
}