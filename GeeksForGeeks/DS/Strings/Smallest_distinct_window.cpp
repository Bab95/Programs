#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#define INT_MAX 100000009
using namespace std;
void solve(){
    string s;
    cin>>s;
    unordered_map<char,int> hash;

    for(int i=0;i<s.length();i++){
        hash[s[i]] = 1;
    }
    int count = hash.size();
    unordered_map<char,int> hash2;
    int i = 0;
    int start = 0;
    int start_index = -1;
    int min_window = INT_MAX;
    while(i<s.length()){
        hash2[s[i]]++;
        if(hash[s[i]]==1){
            hash[s[i]] = 2;
            count--;
        }

        if(count==0){
            while(hash2[s[start]]>1){
                hash2[s[start]]--;
                start++;
            }
            int current_window = i-start+1;
            if(current_window<min_window){
                min_window = current_window;
                start_index = start;
            }
        }
        i++;
    }
    cout<<min_window<<endl;
    /*for(int i=start_index;i<start_index+min_window;i++){
        cout<<s[i];
    }
    cout<<endl;
    */
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
