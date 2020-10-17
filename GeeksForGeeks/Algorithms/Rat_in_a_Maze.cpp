// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

#define MAX 5
vector<string> printPath(int m[MAX][MAX], int n);

// Position this line where user code will be pasted.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int m[MAX][MAX];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }

        vector<string> result = printPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}// } Driver Code Ends


// User function template for C++

// m is the given matrix and n is the order of matrix
// MAX is the upper limit of N ie 5
bool safe(int i,int j,vector<vector<bool>>& visited){
    if(i>=0&&i<visited.size()&&j>=0&&j<visited[0].size()&&!visited[i][j]){
        return true;
    }
    return false;
}
void find_path(int i,int j,int m[MAX][MAX],int& n,vector<vector<bool>>& visited,string current,vector<char>& direction,vector<string>& ans){
    if(i==n-1&&j==n-1){
        ans.push_back(current);
        //current.pop_back();
        return;
    }
    visited[i][j] = true;
    static int dx[] = {-1,1,0,0};
    static int dy[] = {0,0,-1,1};
    for(int k=0;k<4;++k){
        int nx = dx[k] + i;
        int ny = dy[k] + j;
        if(safe(nx,ny,visited)&&m[nx][ny]==1){
            current.push_back(direction[k]);
            find_path(nx,ny,m,n,visited,current,direction,ans);
            current.pop_back();
        }
    }
    visited[i][j] = false;
}
vector<string> printPath(int m[MAX][MAX], int n) {
    // Your code goes here
    vector<vector<bool>> visited(n,vector<bool>(n,false));
    string current = "";
    vector<string> ans;
    vector<char> direction = {'U','D','L','R'};
    if(m[0][0]!=0){
        find_path(0,0,m,n,visited,current,direction,ans);

    }
    if(ans.size()==0){
        return {"-1"};
    }
    sort(ans.begin(),ans.end());
    return ans;
}
