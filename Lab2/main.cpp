#include <stdio.h>
#include<stdlib.h>
#include "liste.h"

int main()
{
    NodeT *first=NULL;
    NodeT *last=NULL;
    insert_first(first,last,4);
    insert_first(first,last,1);
    insert_last(first,last,3);
    delete_key(first,last,1);
    afis(first);
    printf("\n");

    printf("%p\n",search1(first,2));
    printf("%p\n",search1(first,3));



}
