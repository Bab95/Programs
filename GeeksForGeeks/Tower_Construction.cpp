/*

You are given N days to build a tower. Each day you are provided with a distinct brick size. For tower construction, you need to folllow below rules.
1. The bricks with larger sizes should be kept above.
2. The bricks with smaller sizes should be kept below.

So we mainly need to have the largest brick at the bottom and smallest at the top.

Input Format: The input line contains T, denoting the number of testcases. Each testcase contains two lines. The first line contains N, number of days. Second line contains size of bricks provided on ith day.

Output Format: You have to print the sizes of bricks which you can place at ith day in descending order separated by space.

Constraints:
1 <= T <= 100
1 <= N <= 106
1 <= size of brick <= 105

Sample Input:
2
5
4 5 1 2 3
6
7 8 2 9 5 3

Sample Output:
Not possible
5 4 
Not possible
Not possible
3 2 1
Not possible
Not possible
Not possible
9 8 7 
5 
3 2

Explanation:
Testcase 1:
On 1st day, you have brick of size 4 but you cannot place that as size of brick 5 is still remaining.
On 2nd day, you have bricks of size 4, 5 and thus you can place them keeping 5 at the bottom and 4 the top.
On 3rd and 4th day, you cannot place 1 and 2 brick size as size of brick 3 is not yet encountered.
On 5th day, you can place all the bricks of sizes 3 2 1 at the top of tower.



*/



#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <unordered_map>
#include <map>
#include <limits.h>
#include <string.h>
#include <unordered_set>
#include <stack>
#define fo(i,l,r) for(int i=l;i<=r;++i)
#define fi(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back
#define po pop_back
using namespace std;
int Hash[100001];
void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void input(vector<int>& arr,int n){
    fo(i,0,n-1){
        cin>>arr[i];
    }
}
void print(vector<int>& ans,int n){
    fo(i,0,n-1){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    input(arr,n);
    int max_element = INT_MIN;
    memset(Hash,-1,sizeof(Hash));
    int min_element = INT_MAX;
    for(int i=0;i<n;++i){
        Hash[arr[i]] = i;
        max_element = max(max_element,arr[i]);
        min_element = min(min_element,arr[i]);
    }
    unordered_map<int,vector<int> > mmap;
    for(int i=max_element;i>=1;i--){
        if(Hash[i]==-1){
            continue;
        }
        int key = Hash[i];
        mmap[key].push_back(i);
        while(i>0&&Hash[i-1]<key){
            if(Hash[i-1]!=-1){
                mmap[key].push_back(i-1);    
            }
            --i;
        }
        if(Hash[i]>key)
            ++i;
    }
    int count = 0;
    if(arr[0]!=max_element){
        cout<<"Not possible"<<endl;
    }
    for(int i=min_element;i<=max_element;++i){
        //cout<<i<<" :";
        if(mmap.count(i)==0&&Hash[i]!=-1){
            cout<<"Not possible"<<endl;
        }else{
            for(int j=0;j<mmap[i].size();++j){
                cout<<mmap[i][j]<<" ";
                ++count;
            }
            cout<<endl;
        }
        if(count==n){
            return;
        }
    }
    
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}