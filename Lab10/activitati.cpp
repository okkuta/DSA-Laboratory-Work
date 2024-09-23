#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 10

struct activitate
{
    char nume[30];
    int start;
    int fin;
};

void sortare(activitate v[])
{
    int i,j;
    int aux;
    char cop[30];
    for(i=0; i<N; i++)
    {
        for(j=i+1; j<N; j++)
        {
            if(v[i].fin>v[j].fin)
            {
                aux=v[i].fin;
                v[i].fin=v[j].fin;
                v[j].fin=aux;

                aux=v[i].start;
                v[i].start=v[j].start;
                v[j].start=aux;

                strcpy(cop,v[i].nume);
                strcpy(v[i].nume,v[j].nume);
                strcpy(v[j].nume,cop);
            }
        }
    }
}

void alegere(activitate v[])
{
    int k=0;
    activitate sol[N]= {0};

    sol[k]=v[0];
    k++;

    for(int i=1; i<N; i++)
    {
        if(v[i].start>=sol[k-1].fin)
        {
            sol[k]=v[i];
            k++;
        }
    }

    for(int i=0; i<k; i++)
    {
        printf("%s %d %d\n",sol[i].nume,sol[i].start,sol[i].fin);
    }
}

int main()
{
    struct activitate v[N]= {0};
    FILE *f=fopen("activitati.txt","r");
    if(f==NULL)
    {
        printf("Nu s-a putut deschide fisierul!\n");
        exit(1);
    }
    for(int i=0; i<N; i++)
    {
        fscanf(f,"%s",v[i].nume);
        fscanf(f,"%d",&v[i].start);
        fscanf(f,"%d",&v[i].fin);
    }

    sortare(v);
    alegere(v);


}
