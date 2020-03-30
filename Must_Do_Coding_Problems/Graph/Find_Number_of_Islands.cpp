// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findIslands(vector<int> A[], int N, int M);

int main() {

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<int> A[N];
        for (int i = 0; i < N; i++) {
            vector<int> temp(M);
            A[i] = temp;
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
        }
        cout << findIslands(A, N, M) << endl;
    }
    return 0;
}// } Driver Code Ends
/*you are required to complete this method*/

/*  Function to find number of islands in the given graph
*   A[]: input array
*   N, M: Row and column of given matrix
*/
bool safe(vector<int> A[],int i,int j,int N,int M){
    if(i>=0&&i<N&&j>=0&&j<M&&A[i][j]==1){
        return true;
    }
    return false;
}
void dfs(vector<int> A[],int i,int j,int N,int M){
    A[i][j] = 2;
    int row[] = {-1,1,0,0,1,1,-1,-1};
    int col[] = {0,0,-1,1,1,-1,1,-1};
    for(int k=0;k<8;k++){
        int x = i+row[k];
        int y = j+col[k];
        if(safe(A,x,y,N,M)){
            dfs(A,x,y,N,M);
        }
    }
}
int findIslands(vector<int> A[], int N, int M) {

    // Your code here
    int count = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(A[i][j]==1){
                count++;
                dfs(A,i,j,N,M);
            }
        }
    }
    /*for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }*/
    return count;
}
