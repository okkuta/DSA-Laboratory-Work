#include <stdio.h>
#include<stdlib.h>
#include "liste_dublu_inlantuite.h"

int main()
{
    struct list_header L;
    initList(&L);

    insert_first(&L,1);
    insert_first(&L,2);
    insert_first(&L,3);
    insert_last(&L,4);
    insert_last(&L,5);
    insert_last(&L,6);
    insert_last(&L,7);
    insert_after_key(&L,4,10);


    delete_first(&L);
    delete_last(&L);
    delete_key(&L,4);

    print_forward(&L);
    print_backward(&L);

    printf("%p\n",search1(&L,2));
    printf("%p\n",search1(&L,45));

}
