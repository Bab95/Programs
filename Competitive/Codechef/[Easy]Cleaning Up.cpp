#include<stdio.h>
#include<string.h>
int main()
{
    int T;
    scanf("%d",&T);
    char jobs[1001];
    int n,m,temp,flag=0;
    while(T>0) {
        flag = 0;
        memset(jobs,0,sizeof(jobs));
        scanf("%d %d",&n,&m);
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&temp);
            jobs[temp]='d';
        }
        for(int i=1;i<=n;i++)
        {
            if(jobs[i]!='d')
            {
                if(flag==0)
                {
                    jobs[i]='c';
                    flag=1;
                }
                else
                {
                    jobs[i]='a';
                    flag=0;
                }

            }
        }
        for(int i=1;i<=n;i++)
        {
            if (jobs[i] == 'c') {
                printf("%d ", i);
            }
        }
        printf("\n");
        for(int i=1;i<=n;i++)
        {
            if(jobs[i]=='a'){
                printf("%d ",i);
            }
        }
        printf("\n");
        T--;
    }

}
