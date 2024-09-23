#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a[]={1,5,10,50,100,200,500};
    int x;
    int sol[110]={0};
    printf("Introduceti suma:\n");
    scanf("%d",&x);
    int j=0,i=6;

    while(x>0 && i>=0)
    {
        if(x>=a[i])
        {
            x=x-a[i];
            sol[j]=a[i];
            j++;
        }
        else
        {
            i--;
        }
    }
    int m=j;

    printf("Suma poate fi platitia cu bancnotele:\n");
    for(i=0;i<m;i++)
        printf("%d ",sol[i]);
}
