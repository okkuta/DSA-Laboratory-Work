#include<stdio.h>
#include<stdlib.h>


struct NodeT{

    int id;
    NodeT *left;
    NodeT *right;
};

void preorder(NodeT *p)
{
    if(p!=NULL)
    {
        printf("%d ",p->id);
        preorder(p->left);
        preorder(p->right);
    }
}
NodeT *creBalBinTree( int nbOfNodes )

{
    NodeT *p;
    int nLeft, nRight;
    if ( nbOfNodes <= 0 ) return NULL;
    else
    {
        nLeft = nbOfNodes / 2;
        nRight = nbOfNodes - nLeft - 1;
        p = ( NodeT * ) malloc( sizeof( NodeT ));
        printf( "\nNode identifier = ", nLeft, nRight );
        scanf( "%d", &( p->id ));
        p->left = creBalBinTree( nLeft );
        p->right = creBalBinTree( nRight );
    }
    return p;
}
int main()
{
    NodeT *root = NULL;
    int nbOfNodes = 0;
    printf("\nNumarul de noduri din arbore este:");
    scanf("%d", &nbOfNodes );
    root = creBalBinTree( nbOfNodes );

    preorder(root);
    return 0;
}
