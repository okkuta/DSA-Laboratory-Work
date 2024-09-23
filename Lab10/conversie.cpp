#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int x, b;
    printf("Introduceti numarul:\n");
    scanf("%d", &x);
    printf("Introduceti baza:\n");
    scanf("%d", &b);

    int k = 0;
    while (x >= pow(b, k + 1))
    {
        k++;
    }
    int *sol = (int *) calloc(k + 1, sizeof(int));
    int i = k;
    while (i >= 0)
    {
        int cif = x / pow(b, i);
        x = x - cif * pow(b, i);
        sol[k - i] = cif;
        i--;
    }

    for (i = 0; i <= k; i++)
    {
        printf("%d", sol[i]);
    }
    free(sol);
    return 0;
}
