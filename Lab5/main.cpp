#include <stdio.h>
#include <stdlib.h>
#include "arbori_de_cautare.h"
int main()
{
    NodeT *root=NULL;

    root = insertNode(NULL,5);
    insertNode(root,3);
    insertNode(root,7);
    insertNode(root,1);
    insertNode(root,4);
    insertNode(root,6);
    insertNode(root,9);
    insertNode(root,2);
    insertNode(root,8);


    inorder(root);

    printf("\n");
    printf("Minimul este: %d\n",findMin(root)->id);
    printf("Maximul este: %d\n",findMax(root)->id);
    printf("Predecesorul lui %d este: %d\n",7,predecesor(root,7)->id);
    printf("Succesorul lui %d este: %d\n",7,succesor(root,7)->id);
    deleteNode(root,5);
    inorder(root);

}
