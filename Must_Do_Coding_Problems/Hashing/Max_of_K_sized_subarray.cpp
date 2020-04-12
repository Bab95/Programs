#include <iostream>
#include <vector>
using namespace std;
void printans(vector<int>& ans){
    for(int i=0;i<ans.size();++i){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        vector<int> ans;
        if(k==1){
            //ans.insert(arr.begin(),arr.end(),ans.begin());
            printans(arr);
            continue;
        }
        int start = 0,end = k-1;
        int maxelement = arr[end];
        int found = 0;
        while(end<=n-1){
            if(arr[start]>maxelement){
                maxelement = arr[start];
            }
            start++;
            
            if(start==end){
                ans.push_back(maxelement);
                start = ++found;
                end++;
                if(end<n){
                    maxelement = arr[end];
                }
            }
        }
        printans(ans);

    }
    return 0;
}