#include <bits/stdc++.h>
using namespace std;
const int _max = 1e5 + 5;
typedef long long int lli;
#define endl "\n";
#define speed ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    int a=INT_MAX,b=INT_MIN;
    for(int i=0;i<n;++i){
        a = min(a,arr[i]);
        b = max(b,arr[i]);
    }
    vector<int> vals(n,-1);
    for(int i=0;i<n;++i){
        if(arr[i]==a){
            vals[i] = a;
        }else if(arr[i]==b){
            vals[i] = b;
        }
    }
    int window = INT_MAX;
    for(int i=0;i<n;++i){
        if(vals[i]!=-1){
            if(vals[i]==a){
                for(int j=i;j<n;++j){
                    if(vals[j]==b){
                        window = min(window,j-i+1);
                    }
                }
            }else if(vals[i]==b){
                for(int j=i;j<n;++j){
                    if(vals[j]==a){
                        window = min(window,j-i+1);
                    }
                }
            }
        }
    }
    /*
    for(int i=0;i<vals.size();++i){
        cout<<vals[i]<<" ";
    }
    cout<<endl;
    */
    cout<<window<<endl;
    return 0;
}
