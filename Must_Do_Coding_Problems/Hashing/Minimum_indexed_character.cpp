#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
/*template <typename T>
void input(vector<T>& arr,int length){
    for(int i=0;i<length;++i){
        cin>>arr[i];
    }
}*/
#define INT_MAX 100000009
int main(){
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1;
        cin>>s2;
        unordered_map<char,int> map;
        for(int i=0;i<s1.length();i++){
            if(map.find(s1[i])==map.end()){
                map[s1[i]] = i;
            }
        }
        int min_index = INT_MAX;
        char ans = '$';
        for(int i=0;i<s2.length();++i){
            if(map.count(s2[i])==0){
                continue;
            }else{
                if(min_index>map[s2[i]]){
                    min_index = map[s2[i]];
                    ans = s2[i];
                }
            }
        }
       cout<<ans<<endl;
    }
}
