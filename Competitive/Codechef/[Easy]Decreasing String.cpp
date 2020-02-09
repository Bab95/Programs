#include<stdio.h>
int main()
{
	int T,K,t;
	register int i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&K);
		t = K%25;
		if((t!=0)||K==0)
		{
			for(i=97+t;i>=97;i--)
			{
				printf("%c",i);
			}
		}
		t = K/25;
		for(int j=1;j<=t;j++)
		{
			printf("zyxwvutsrqponmlkjihgfedcba");
		}
	printf("\n");
	}
}
