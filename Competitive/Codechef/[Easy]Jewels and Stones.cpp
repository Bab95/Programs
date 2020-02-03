#include<stdio.h>
#include<string.h>
char S[100];
inline void fast_read_string(char *str)
{
	register char c = 0;
	register int i = 0;
	while(c<33)
	{
		c = getchar_unlocked();
	}
	while(c!='\n')
	{
		str[i] = c;
		c = getchar_unlocked();
		i = i+1;
	}
	str[i] = '\0';
}
inline int scan()
{
	register int c=getchar_unlocked();
	int x=0;
	for(;(c<48||c>57);c=getchar_unlocked());
	for(;(c>47&&c<58);c=getchar_unlocked()){x= (x<<1) + (x<<3) + c-48;}
	return x;
}
void Jewels()
{
	int J[52]={0};
	register int i = 0,l=0;
	register char c = 0;
	memset(S,0,sizeof(S));
	//printf("Enter the string J:\n");
	c = getchar_unlocked();
	for(;c!='\n';c=getchar_unlocked())
	{
		if(c>='A'&&c<='Z')
		{
			J[((int)c-65)]++;
		}
		if(c>='a'&&c<='z')
		{
			J[((int)c-97)+26]++;
		}
	}
	memset(S,0,sizeof(S));
	//printf("Enter the string S:\n");
	fast_read_string(S);
	for(c=S[l];l<strlen(S)&&c!='\0';c=S[++l])
	{
		if(c>='A'&&c<='Z')
		{
			if(J[((int)c-65)]>0)
			{
				//printf("%c",c);
				i++;
			}
			else
			{
				continue;
			}
		}
		if(c>='a'&&c<='z')
		{
			if(J[((int)c-97)+26]>0)
			{
				//printf("%c",c);
				i++;
			}
			else
			{
				continue;
			}
		}
	}
		printf("%d\n",i);
}
int main()
{
	int T;
	T = scan();
	while(T--)
	{
		Jewels();
	}
}
