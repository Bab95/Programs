#include<stdio.h>
int main()
{
    int A,B,C,rem;
    scanf("%d%d",&A,&B);
    C = A-B;
    rem = C%10;
    if(rem<9)
    {
        C++;
    }
    else
    {
        C--;
    }
    printf("%d",C);

}
