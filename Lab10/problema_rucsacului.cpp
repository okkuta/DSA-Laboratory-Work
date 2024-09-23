#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct obiect{

    char nume[20];
    int w;
    int p;
    float d;

};

int main()
{

    FILE *f=fopen("obiecte.txt","r");
    if (f==NULL)
    {
        printf("Nu s-a putut deschide fisierul\n");
        exit(1);
    }

    int n,i;
    int W;
    int P=0;
    fscanf(f,"%d",&W);
    fscanf(f,"%d",&n);

    struct obiect v[n]={0};


    printf("\nDatele despre cele %d obiecte au fost citite din fisiser",n);
    for(i=0;i<n;i++)
    {
        fscanf(f,"%s",v[i].nume);
        fscanf(f,"%d",&v[i].w);
        fscanf(f,"%d",&v[i].p);
    }

    //calculam densitatea fiecarui obiect precum si pretul total al acestora
    for(i=0;i<n;i++) {
        v[i].d=(float) v[i].p/v[i].w;
        P=P+v[i].p;
    }



    struct obiect sol[n]={0};

    int j;
    float aux;
    char cop[30];

    //sortam obiectele in functie de densitate
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
        {
            if(v[i].d<v[j].d)
            {
                aux=v[i].p;
                v[i].p=v[j].p;
                v[j].p=aux;

                aux=v[i].d;
                v[i].d=v[j].d;
                v[j].d=aux;

                aux=v[i].w;
                v[i].w=v[j].w;
                v[j].w=aux;

                strcpy(cop,v[i].nume);
                strcpy(v[i].nume,v[j].nume);
                strcpy(v[j].nume,cop);
            }
        }

    printf("\nNumarul de obiecte este: %d\n",n);
    printf("Capacitatea rucsacului este de %d kg\n",W);
    printf("\nObiectele dupa sortare sunt:\n");
    for(i=0;i<n;i++)
    {
        printf("%s %d %d %f\n",v[i].nume,v[i].w,v[i].p,v[i].d);
    }

    j=0;
    i=0;
    while(W>0 && i<n)
    {
        if(W>=v[i].w)
        {
            W=W-v[i].w;
            strcpy(sol[j].nume,v[i].nume);
            sol[j].d=v[i].d;
            sol[j].p=v[i].p;
            sol[j].w=v[i].w;
            j++;

        }
        i++;


    }

    int m=j-1;
    printf("\nO solutie este:\n");
    for(i=0;i<=m;i++)
        printf("%s, ",sol[i].nume);


}
