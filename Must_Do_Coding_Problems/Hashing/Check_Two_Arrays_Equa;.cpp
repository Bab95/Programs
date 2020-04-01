#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
void input(vector<string>& arr,int n){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}
int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        unordered_map<string,int> map;
        vector<string> arr(n);
        vector<string> brr(n);
        input(arr,n);
        input(brr,n);
        for(int i=0;i<n;i++){
            map[arr[i]]++;
        }
        for(int i=0;i<n;i++){
            map[brr[i]]--;
        }
        unordered_map<string,int>::iterator itr;
        bool flag = false;
        for(itr=map.begin();itr!=map.end();++itr){
            if(itr->second!=0){
                flag = true;
                break;
            }
        }
        if(flag){
            cout<<"0"<<endl;
        }else{
            cout<<"1"<<endl;
        }
    }
    return 0;
}
