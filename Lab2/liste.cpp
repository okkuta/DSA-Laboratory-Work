#include<stdio.h>
#include"liste.h"
#include<stdlib.h>

void afis(NodeT *first)
{
    NodeT *p=first;
    while(p!=NULL)
    {
        printf("%d ",p->val);
        p=p->next;
    }
}
NodeT* search1(NodeT* first, int givenKey)
{
    NodeT *p=first;

    while(p->val!=givenKey && p->next!=NULL)
    {
        p=p->next;

    }
    if(p->val==givenKey)
        return p;

    else if(p==NULL)
        return NULL;

}
void insert_first(NodeT* &first, NodeT* &last, int givenKey)
{
    NodeT *p= ( NodeT * )malloc(sizeof(NodeT));
    p->val=givenKey;
    p->next=NULL;

    p->next=first;
    first=p;

}
void insert_last(NodeT* &first, NodeT* &last, int givenKey)
{
    NodeT *p= ( NodeT * )malloc(sizeof(NodeT));
    p->val=givenKey;
    p->next=NULL;

    NodeT *q=first;
    while(q->next!=NULL)
        q=q->next;
    q->next=p;
    last=p;



}
void insert_after_key(NodeT* &first, NodeT* &last, int afterKey, int givenKey)
{
    NodeT *p= ( NodeT * )malloc(sizeof(NodeT));
    p->val=givenKey;
    p->next=NULL;

    NodeT *q=first;

    while(q->val!=afterKey)
        q=q->next;

    NodeT *r=q->next;

    q->next=p;
    p->next=r;


}
void delete_first(NodeT* &first, NodeT* &last)
{
    NodeT *p=first;
    first=first->next;
    free(p);
}
void delete_last(NodeT* &first, NodeT* &last)
{
    NodeT *p=first;
    while(p->next->next!=NULL)
        p=p->next;
    NodeT *q=p->next;
    p->next=NULL;
    free(q);
    last=p;
}
void delete_key(NodeT* &first, NodeT* &last,int givenKey)
{
    NodeT *p=first;
    int ok=0;

    while(p->next!=NULL)
    {
        if(p->next->val==givenKey);
        {
            ok=1;
            break;
        }
        p=p->next;
    }
    if(ok==0)
        return;
    else if(ok==1)
    {
        NodeT *q= p->next;
        free(q);
        p->next=p->next->next;
    }

}


