/* trebuie sa se plaseze n regine pe o tabla de sah n*n
astfel incat sa nu se atace (sa nu se afle pe aceeasi linie/diagonala)
*/
#include<stdio.h>
#include<stdlib.h>

void afisare(int n,int *v)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(v[i]==j)
                printf("R");
            else
                printf(".");
        }
        printf("\n");
    }
    printf("\n");
}

bool verif(int pos,int *v)
{
    for(int i=1; i<pos; i++)
    {
        if(v[i]==v[pos] || abs(v[i]-v[pos])==abs(i-pos))
            return false;
    }
    return true;
}
void backtracking(int n,int *v)
{
    int pos=1;
    bool valid;

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
                afisare(n,v);
            else
                pos++;
        }

    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int *v=(int *)calloc(n+1,sizeof(int));

    backtracking(n,v);

    free(v);
}
