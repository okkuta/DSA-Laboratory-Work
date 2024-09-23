#include<stdio.h>
#include<stdlib.h>

int main()
{
    int m,n;
    scanf("%d%d",&n,&m);
    int a[n+1][m+1];
    int i,j;

    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            scanf("%d",&a[i][j]);

    for(j=0; j<m; j++)
    {
        int mx=0;
        int k=0;
        while(k<n)
        {
            int l=1;
            i=k;

            while(a[i][j]<a[i+1][j])
            {
                i++;
                l++;
            }
            if(l>mx)
                mx=l;
            k++;
        }
        printf("%d ",mx);
    }

}
