#include<stdio.h>
#include<stdlib.h>
#include "arbori_de_cautare.h"

NodeT* insertNode(NodeT* root, int key )
{
    NodeT* p=(NodeT *)malloc(sizeof(NodeT));
    p->parinte=NULL;
    p->left=p->right=NULL;
    p->id=key;

    NodeT *q=root;
    while(q!=NULL)
    {
        if(key < q->id)
        {
            if(q->left==NULL)
            {
                q->left=p;
                p->parinte=q;
                break;
            }
            q=q->left;
        }
        else if(key > q->id)
        {
            if(q->right==NULL)
            {
                q->right=p;
                p->parinte=q;
                break;
            }
            q=q->right;
        }
        else //nodul este deja in arbore
        {
            return q;
        }

    }

    if(q==NULL)
        return p;
}
void preorder(NodeT *p)
{
    if(p!=NULL)
    {
        printf("%d ",p->id);
        preorder(p->left);
        preorder(p->right);
    }
    else return;
}
void inorder(NodeT *p)
{
    if(p!=NULL)
    {
        inorder(p->left);
        printf("%d ",p->id);
        inorder(p->right);
    }

}
void postorder(NodeT *p)
{
    if(p!=NULL)
    {
        postorder(p->left);
        postorder(p->right);
        printf("%d ",p->id);
    }
    else
        return;
}
NodeT* findMin(NodeT *root)
{
    NodeT *p=root;
    while(p->left!=NULL)
    {
        p=p->left;
    }
    return p;
}
NodeT* findMax(NodeT *root)
{
    NodeT *p=root;
    while(p->right!=NULL)
    {
        p=p->right;
    }
    return p;
}
NodeT *searchKey(NodeT *root,int key)
{
    NodeT *p=root;
    while(p!=NULL)
    {
        if(p->id==key)
            return p;
        else if(p->id>key)
            p=p->left;

        else
            p=p->right;
    }
}
NodeT* succesor(NodeT* root,int key)
{

    NodeT *nod=searchKey(root,key);

    if(nod==findMax(root))
        return NULL;

    if(nod->right!=NULL)
    {
        nod=nod->right;
        while(nod->left!=NULL)
            nod=nod->left;
        return nod;
    }
    else
    {
        NodeT*p=nod->parinte;
        while(p!=NULL && nod==p->right)
        {
            nod=p;
            p=p->parinte;
        }
        return p;
    }

}
NodeT* predecesor(NodeT* root,int key)
{
    NodeT *nod=searchKey(root,key);

    if(nod==findMin(root))
        return NULL;


    /* daca nodul are fiu stang,
    predecesorul va fi cel mai din dreapta nod din subarborele lui stang*/
    if(nod->left!=NULL)
    {
        nod=nod->left;
        while(nod->right!=NULL)
            nod=nod->right;

        return nod;
    }
    else
    {

        NodeT *p=nod->parinte;
        /* daca nodul nu are fiu stang
        predecesorul lui este primul parinte stang*/
        while(p!=NULL && nod==p->left)
        {
            nod=p;
            p=p->parinte;
        }

        return p;
    }
}

NodeT* deleteNode(NodeT* root, int key)
{
    NodeT* victima=searchKey(root,key);
    NodeT* parent=victima->parinte;

    //nodul nu are fii (este frunza)

    if(victima->left==NULL && victima->right==NULL)
    {
        if(parent==NULL)
        {
            free(victima);
            return NULL;
        }
        if(parent->left==victima)
        {
            parent->left=NULL;

        }
        else
            parent->right==NULL;

        free(victima);
        return root;
    }

    //nodul are un singur fiu

    if(victima->left==NULL || victima->right==NULL)
    {
        NodeT *fiu=NULL;
        if(victima->left!=NULL)
            fiu=victima->left;
        else
            fiu=victima->right;

        if(parent==NULL)
        {
            free(victima);
            return NULL;
        }
        if(parent->left!=NULL)
        {
            parent->left=fiu;
        }
        else
            parent->right=fiu;
        free(victima);
        return root;
    }

    //nodul are 2 fii

    NodeT *urmator=succesor(root,key);
    int c=urmator->id;
    root=deleteNode(root,c);
    victima->id=c;

    return root;

}
