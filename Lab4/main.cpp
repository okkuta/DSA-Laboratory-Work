#include <bits/stdc++.h>
#include "arbori_binari.h"

int main()
{
    FILE *f=fopen("ArboreBinar.txt","r");
    if(f==NULL)
    {
        printf("Nu s-a putut deschide fisierul\n");
        exit(1);
    }
    NodeT *root=createBinTreeFromFile(f);

    printf("Arborele initial este:\n");
    preorder(root);
    printf("\n");

    printf("Nr de frunze ale arborelui este:\n");
    printf("%d",leaf_node(root));
    printf("\n");

    printf("Numarul de noturi interne ale arborelui este:\n");
    printf("%d",nr_intern_nodes(root)-1);
    printf("\n");

    printf("Inaltimea arborelui este:\n");
    printf("%d",height(root));
    printf("\n");

    printf("Diametrul arborelui este:\n");
    printf("%d",diameter(root));
    printf("\n");

    insertLeft(root,2,10);
    printf("Arborele dupa ce s-a inserat nodul 10 ca fiu stang al nodului 2 este:\n");
    preorder(root);
    printf("\n");

    insertRight(root,3,11);
    printf("Arborele dupa ce s-a inserat nodul 11 ca fiu drept al nodului 3 este:\n");
    preorder(root);
    printf("\n");

    deleteNod(root,4);
    printf("Arborele dupa ce s-a sters nodul cu eticheta 4 este:\n");
    preorder(root);
    printf("\n");


    fclose(f);
}
