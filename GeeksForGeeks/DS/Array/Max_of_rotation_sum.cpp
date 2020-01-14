#include<bits/stdc++.h>
using namespace std;

int max_sum(int A[],int N);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
        {
            cin>>A[i];
        }

        cout<<max_sum(A,N)<<endl;
        /*keeping track of the total sum of the array*/

    }
}
// } Driver Code Ends
/*You are required to complete this method*/
int max_sum(int A[],int N)
{
//Your code here
    int current_rotation = 0;
    int sum = 0;
    for(int i=0;i<N;i++){
        current_rotation+=(A[i])*i;
        sum+=A[i];
    }
    int next_rotation = 0;
    int result = current_rotation;
    for(int i=0;i<N-1;i++){
        next_rotation = current_rotation-sum+N*A[i];
        result = max(result,next_rotation);
        current_rotation = next_rotation;
    }
    return result;
}
