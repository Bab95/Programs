#include<stdio.h>
int main() {
	int n;
	scanf("%d",&n);
	char c[n][n];
	int a;
	for(int i=0;i<n;i++)
	{
		scanf("%s",c[i]);
	}
	for(int i=1;i<n-1;i++)
	{
		for(int j=1;j<n-1;j++)
		{
			a = (int)c[i][j];
			if(a>(int)c[i][j-1]&&a>(int)c[i-1][j]&&a>(int)c[i][j+1]&&a>c[i+1][j])
			{
				c[i][j] = 'X';
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%c",c[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return 0;
}
