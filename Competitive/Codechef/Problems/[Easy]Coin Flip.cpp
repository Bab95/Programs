#include <stdio.h>
int main()
{
    int T,G,I,N,Q,ans;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&G);
        while(G--)
        {
            scanf("%d %d %d",&I,&N,&Q);
            ans = N/2;
            if((I!=Q)&&(N%2!=0))
            {
                ans = ans+1;
            }
            printf("%d\n",ans);

        }


    }
}
