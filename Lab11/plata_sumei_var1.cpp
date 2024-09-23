#include<stdio.h>
#include<stdlib.h>
void functie(int S,int n,int *monede,int *combinatii)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        int c=monede[i];
        for(j=c;j<=S;j++)
            combinatii[j]=combinatii[j]+combinatii[j-c];
    }
}

int main()
{
    int S,n;
    printf("Introduceti suma:\n");
    scanf("%d",&S);

    printf("Introduceti nr de monede:\n");
    scanf("%d",&n);

    int monede[n+1],i;
    printf("Introduceti monedele:\n");
    for(i=0;i<n;i++)
        scanf("%d",&monede[i]);

    int *combinatii=(int *)calloc(S+1,sizeof(int));
    combinatii[0]=1;

    functie(S,n,monede,combinatii);

    for(i=0;i<=S;i++)
        printf("%d ",combinatii[i]);

}
