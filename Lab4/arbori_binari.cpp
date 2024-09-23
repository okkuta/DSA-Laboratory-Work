#include <bits/stdc++.h>
#include"arbori_binari.h"

int maxi(int x,int y)
{
    if(x>y)
        return x;
    else
        return y;
}

NodeT *createBinTreeFromFile(FILE* f)
{
    NodeT *p;
    int c;

    fscanf(f,"%d",&c);
    if(c==0)
        return NULL;
    else
    {
        p=(NodeT *)(malloc(sizeof(NodeT)));
        if(p==NULL)
            return NULL;
        p->id=c;
        p->left=createBinTreeFromFile(f);
        p->right=createBinTreeFromFile(f);
    }

}

void preorder(NodeT *p)
{
    if(p!=NULL)
    {
        printf("%d ",p->id);
        preorder(p->left);
        preorder(p->right);
    }
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
}

int leaf_node(NodeT *p)
{
    if(p==NULL)
        return 0;
    else if(p->left==NULL && p->right==NULL)
    {
        return 1;
    }
    else
        return leaf_node(p->left)+leaf_node(p->right);
}
int nr_total_nodes(NodeT *p)
{
    if(p==NULL)
        return 1;
    else
    {
        return nr_total_nodes(p->left)+nr_total_nodes(p->right);
    }
}
int nr_intern_nodes(NodeT *p)
{
    return nr_total_nodes(p)-leaf_node(p);

}
int height(NodeT *p)
{
    if(p==NULL)
    {
        return -1;
    }
    int h_left=height(p->left);
    int h_right=height(p->right);

    return ((h_left>h_right) ? h_left : h_right)+1;

}

int diameter(NodeT *p)
{
    if(p==NULL)
    {
        return 0;
    }
    int h_left,h_right;
    if(p->left)
        h_left=height(p->left);

    if(p->right)
        h_right=height(p->right);


    int d_left=diameter(p->left);
    int d_right=diameter(p->right);

    return maxi(h_left+h_right+2, maxi(d_left,d_right));


}
NodeT  *searc(NodeT *p,int value)
{

    int v[10]= {0}; // acesta este vectorul aparitiilor, se va marca cu 1 nodul care a fost vizitat
    NodeT *q=p;
    NodeT *r=q;
    while(q!=NULL)
    {
        if(q->id==value)
            return q;
        else
        {
            v[q->id]=1;

            if(q->left!=NULL && q->right!=NULL)
            {
                if(v[q->left->id]!=1)
                {
                    r=q;
                    q=q->left;
                }
                else if(v[q->right->id]!=1)
                {
                    r=q;
                    q=q->right;
                }
                else if(v[q->right->id]==1 && v[q->left->id]==1)
                    q=r;

            }
            else if(q->left!=NULL && q->right==NULL)
            {

                if(v[q->left->id]!=1)
                {
                    r=q;
                    q=q->left;
                }

            }
            else if(q->left==NULL && q->right!=NULL)
            {
                if(v[q->right->id]!=1)
                {
                    r=q;
                    q=q->right;
                }
            }
            else if(q->left==NULL && q->right==NULL)
            {
                if(p->right!=NULL)
                {
                    p=p->right;
                }
                else if(p->left!=NULL)
                {
                    p=p->left;
                }
                else if(p->left==NULL && p->right==NULL)
                    p=NULL;
                q=p;
            }

        }
    }
    if(q==NULL)
        return NULL;
}
void deleteTree(NodeT* &p)
{
    NodeT* q=p;
    if(p==NULL);

    deleteTree(q->left);
    deleteTree(q->right);
    free(q);
}
void insertLeft(NodeT* &p,int value,int x)
{
    NodeT *nod=(NodeT *)(malloc(sizeof(NodeT)));
    nod->id=x;
    nod->right=nod->left=NULL;

    NodeT *q=searc(p,value);

    if(q->id==value)
    {
        NodeT *r=q->left;
        q->left=nod;
        nod->left=r;
    }
    else if(q==NULL)
        printf("Nu exista nod dupa care sa se insereze\n");
}
void insertRight(NodeT* &p,int value,int x)
{
    NodeT *nod=(NodeT *)(malloc(sizeof(NodeT)));
    nod->id=x;
    nod->right=nod->left=NULL;

    NodeT *q=searc(p,value);


    if(q->id==value)
    {
        NodeT *r=q->right;
        q->right=nod;
        nod->right=r;
    }
    else if(q==NULL)
        printf("Nu exista nod dupa care sa se insereze\n");
}
NodeT* generateParent(NodeT *p,int value)
{
    int v[10]= {0};
    NodeT *q=p;
    NodeT *r=q;
    while(q!=NULL)
    {
        if(q->left!=NULL)
        {
            if(q->left->id==value)
                return q;
        }
        if(q->right!=NULL)
        {
            if(q->right->id==value)
                return q;
        }

        v[q->id]=1;

        if(q->left!=NULL && q->right!=NULL)
        {
            if(v[q->left->id]!=1)
            {
                r=q;
                q=q->left;
            }
            else if(v[q->right->id]!=1)
            {
                r=q;
                q=q->right;
            }
            else if(v[q->right->id]==1 && v[q->left->id]==1)
                q=r;

        }
        else if(q->left!=NULL && q->right==NULL)
        {

            if(v[q->left->id]!=1)
            {
                r=q;
                q=q->left;
            }

        }
        else if(q->left==NULL && q->right!=NULL)
        {
            if(v[q->right->id]!=1)
            {
                r=q;
                q=q->right;
            }
        }
        else if(q->left==NULL && q->right==NULL)
        {
            if(p->right!=NULL)
            {
                p=p->right;
            }
            else if(p->left!=NULL)
            {
                p=p->left;
            }
            else if(p->left==NULL && p->right==NULL)
                p=NULL;
            q=p;
        }


    }
    if(q==NULL)
        return NULL;
}
void deleteNod(NodeT* &p,int value)
{
    NodeT *q=generateParent(p,value);
    NodeT *victima;
    if(q->left->id==value)
    {
        victima=q->left;
    }
    else if(q->right->id==value)
    {
        victima=q->right;
    }

    NodeT *s=victima->left;
    NodeT *d=victima->right;

    free(victima);
    q->left=s;
    q->right=d;


}
