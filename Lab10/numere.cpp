#include<stdio.h>
#include<stdlib.h>

void sortare(int n,int a[])
{
    int i,j,aux;
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)

            if(a[i]>a[j])
            {
                aux=a[i];
                a[i]=a[j];
                a[j]=aux;
            }
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int *a=(int *)malloc((n+1)*sizeof(int));

    int i;
    for(i=0; i<n; i++)
        scanf("%d",&a[i]);

    int L=0;
    for(i=0; i<n; i++)
        L=L+a[i];
    a[n]=-1;

    sortare(n,a);
    printf("(%d+%d)",a[0],a[1]);
    i=2;
    while(i<n)
    {
        if(a[i+1]!=-1)
            printf("+(%d+%d)",a[i],a[i+1]);
        else
            printf("+%d",a[i]);
        i=i+2;
    }



}
