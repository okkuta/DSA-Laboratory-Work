#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void afisare(int n,int k,int *v)
{
    for(int i=1; i<=k; i++)
        printf("%d ",v[i]);
    printf("\n");

}

//verifica daca solutia gasita e buna
bool verif(int pos,int *v)
{
   for(int i=1; i<pos; i++)
    {
        if(v[pos]==v[i])
            return false;
    }
    return true;
}

void backtracking(int n,int k,int *v)
{
    int pos=1;
    bool valid=false;
    while(pos>0)
    {

        valid=false;
        while(v[pos]<n && valid==false)
        {
            v[pos]++;
            valid=verif(pos,v);

        }
        if(valid==false)
        {
            v[pos]=0;
            pos--;
        }
        else
        {
            if(pos==k)
            {
                afisare(n,k,v);
            }
            else
            {
                pos++;
            }
        }

    }

}


int main()
{
    int n,k;
    int *v=NULL;

    scanf("%d",&n);
    scanf("%d",&k);
    v=(int *)calloc(k+1,sizeof(int));

    printf("Aranjamentele de %d luate cate %d sunt:\n",n,k);
    backtracking(n,k,v);

    free(v);

}

