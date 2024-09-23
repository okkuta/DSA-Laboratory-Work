#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    long x;
    scanf("%d",&x);
    int k=0;
    while(x>=pow(2,k))
        k++;

    long c;
    while(x!=0)
    {
        c=pow(2,k);
        if(x>=c)
        {
            x=x-c;
            printf("%d ",c);
        }
        else
            k--;

    }


}
