#include <bits/stdc++.h>
using namespace std;
bool solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    int count5 = 0;
    int count10 = 0;
    for(int i=0;i<n;++i){
        if(arr[i]==5){
            count5++;
        }else{
            if(arr[i]==10){
                if(count5==0){
                    return false;
                }else{
                    count5--;
                    count10++;
                }
            }else if(arr[i]==15){
                if(count10==0&&count5<2){
                    return false;
                }else if(count10>0){
                    count10--;
                }else if(count5>1){
                    count5-=2;
                }else{
                    return false;
                }
            }
        }
    }
    return true;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        if(solve()){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}
