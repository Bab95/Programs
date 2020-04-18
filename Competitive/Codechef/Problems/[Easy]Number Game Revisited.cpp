#include<stdio.h>
int main()
{
	int t;
	long n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%ld",&n);
		if((n-1)%4==0)
		{
			printf("ALICE\n");
		}
		else
		{
			printf("BOB\n");
		}
	}
}
