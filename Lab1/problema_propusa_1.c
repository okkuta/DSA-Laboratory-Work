#include<stdio.h>
#include<stdlib.h>

typedef struct
{

    char nume[15];
    char prenume[15];
    int varsta;
    float note[4];
    float media;

} elev;
/*
elev **alocare(int n)
{
    elev **v=malloc(n*sizeof(elev *));
    for(int i=0; i<n; i++)
    {
        v[i]->nume=malloc(10*sizeof(elev));
        v[i]->prenume=malloc(10*sizeof(elev));
        v[i]->note=malloc(4*sizeof(elev));
    }
    return v;
}
*/
int main()
{
    FILE *f=fopen("elevi.txt","r");
    if(f==NULL)
    {
        printf("Nu se poate citi din fisier\n");
        exit(1);
    }

    int n,i;
    fscanf(f,"%d",&n);
    elev v[100];

    for(i=0; i<n; i++)
    {
        fscanf(f,"%s",v[i].nume);
        fscanf(f,"%s",v[i].prenume);
        fscanf(f,"%d",&v[i].varsta);

        for(int j=0; j<3; j++)
            fscanf("%f",&v[i].note[j]);
    }
    for(i=0; i<n; i++)
    {
        float s=0.0;
        for(int j=0; j<3; j++)
            s=s+v[i].note[j];

        v[i].media=s/3;
    }
    printf("Sirul de studenti si media fiecaruia este:\n");
    for(i=0; i<n; i++)
    {
        printf(f,"%s ",v[i].nume);
        printf(f,"%s ",v[i].prenume);
        printf(f,"%d ",v[i].varsta);

        for(int j=0; j<3; j++)
            printf("%f ",v[i].note[j]);

        printf("%f ",v[i].media);
        printf("\n");

    }

    printf("Sirul de studenti cu notele incrementate cu 1 este:");
    {
        printf("%s %s %d ",v[i].nume,v[i].prenume,v[i].varsta);
        for(int j=0; j<3; j++)
        {
            v[i].note[j]++;
            printf("%f ",v[i].note[j]);
        }

    }
}

