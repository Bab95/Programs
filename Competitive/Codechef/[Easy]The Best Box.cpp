#include<stdio.h>
#include<math.h>
inline int scan()
{
	register int c=getchar_unlocked();
	int x=0;
	for(;(c<48||c>57);c=getchar_unlocked());
	for(;(c>47&&c<58);c=getchar_unlocked()){x= (x<<1) + (x<<3) + c-48;}
	return x;
}
int main()
{
	int T,P,S;
	float x,y,v;
	T = scan();
	while(T--)
	{
		P = scan();
		S = scan();
		//solving Quadratic Equation and maximizing Volume
		y = (P - sqrt(P*P-24*S))/12;
		x = (P/4) - 2*y;
		v = (y*S)/2-(y*y*P)/4+(y*y*y);
		printf("%.2f\n",v);

	}
}
