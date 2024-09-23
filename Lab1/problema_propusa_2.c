#include<stdio.h>
#include<stdlib.h>
void adauga(float *v,int *n,float x)
{
    v[*n]=x;
    (*n)++;

}
int main()
{
    int capacity, size;
    scanf("%d%d",&capacity,&size);
    float *v=malloc((size+capacity)*sizeof(float));

    for(int i=0;i<capacity;i++)
        scanf("%f",&v[i]);

    for(int j=1;j<=size;j++)
    {

        adauga(v,&capacity,26);
    }
    for(int i=0;i<capacity;i++)
        printf("%f ",v[i]);
}
