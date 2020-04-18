#include<stdio.h>
#include<string.h>
void carvas(int N)
{
    int A[10000],speed_limit;
    memset(A,0,sizeof(A));
    for(int i=0;i<N;i++)
    {
        scanf("%d",&A[i]);
    }
    int c=1;
    speed_limit = A[0];
    for(int i=1;i<=N-1;i++)
    {
        if(A[i]<speed_limit)
        {
            c++;
            speed_limit = A[i];
            //printf("%d",A[i]);
        }
    }
    printf("%d\n",c);
}
int main()
{
    int T,N;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        carvas(N);
    }
}
