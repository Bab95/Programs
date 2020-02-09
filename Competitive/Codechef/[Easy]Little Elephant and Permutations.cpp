#include<stdio.h>
inline int scan()
{
	register int c=getchar_unlocked();
	int x=0;
	for(;(c<48||c>57);c=getchar_unlocked());
	for(;(c>47&&c<58);c=getchar_unlocked()){x= (x<<1) + (x<<3) + c-48;}
	return x;
}
void LEAP()
{
	int N;
	register int i=0,j=0,inv=0,linv=0;
	N = scan();
	int A[100]={0};
	for(int i=0;i<N;i++)
	{
		A[i] = scan();
	}
	for(i=0;i<N-1;i++)
	{
		for(j=i+1;j<N;j++)
		{
			if(A[i]>A[j])
			{
				inv++;
			}
		}
		if(A[i]>A[i+1])
		{
			linv++;
		}
	}
	if(inv==linv)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}
int main()
{
	int T;
	T = scan();
	while(T--)
	{
		LEAP();
	}
}
