#include<stdio.h>
#include<stdlib.h>

int main()
{
    int S,n;
    printf("Introduceti suma:\n");
    scanf("%d",&S);

    printf("Introduceti nr de monede:\n");
    scanf("%d",&n);

    int monede[n+1],i,j;
    printf("Introduceti monedele:\n");
    for(i=0;i<n;i++)
        scanf("%d",&monede[i]);

    int *mini=(int*)calloc(S+1,sizeof(int));
    mini[0]=0;

    for(i=1;i<=S;i++)
        mini[i]=9999999;
    for(i=1;i<=S;i++)
    {
        for(j=0;j<n;j++)
            if(monede[j]<=i && mini[i-monede[j]]+1<mini[i])
                mini[i]=mini[i-monede[j]]+1;
    }
    printf("Numarul minim de monede este %d",mini[S]);
}
