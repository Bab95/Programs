#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1;
        cin>>s2;
        unordered_map<char,int> map;
        for(int i=0;i<s1.length();++i){
           map[s1[i]]++;
        }
        unordered_map<char,int> map2;
        for(int i=0;i<s2.length();i++){
            map2[s2[i]]++;
        }
        unordered_map<char,int>::iterator itr;
        unordered_map<char,int>::iterator itr2;
        vector<char> result;
        for(itr=map.begin();itr!=map.end();++itr){
            /*if(map2.find(itr->first)==map2.end()){
                result.push_back(itr->first);
            }*/
            if(map2.count(itr->first)==0){
                result.push_back(itr->first);
            }
        }
        for(itr=map2.begin();itr!=map2.end();++itr){
            /*if(map.find(itr->first)==map.end()){
                result.push_back(itr->first);
            }*/
            if(map.count(itr->first)==0){
                result.push_back(itr->first);
            }
        }
        sort(result.begin(),result.end());
        for(int i=0;i<result.size();i++){
            cout<<result[i];
        }
        cout<<endl;
    }
}
