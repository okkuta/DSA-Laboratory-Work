#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
void afisare(int n,int *v)
{
    for(int i=1; i<=n; i++)
        printf("%d ",v[i]);
    printf("\n");

}

//verifica daca solutia gasita e buna
bool verif(int pos,int *v)
{
    for(int i=1; i<pos; i++)
    {
        if(v[pos]==v[i] || abs()
    }
    return true;
}

void backtracking(int n,int *v)
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
            if(pos==n)
            {
                afisare(n,v);
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
    int n;
    int *v=NULL;

    scanf("%d",&n);
    v=(int *)calloc(n+1,sizeof(int));

    printf("Permutarile de %d sunt:\n",n);
    backtracking(n,v);

    free(v);


}
