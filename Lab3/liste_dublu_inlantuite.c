#include<stdio.h>
#include<stdlib.h>
#include "liste_dublu_inlantuite.h"

//initializare
void initList(struct list_header* L)
{
    L->first = NULL;
    L->last = NULL;
}
//creare un nod nou
struct NodeDL *createNod(int x)
{
    struct NodeDL *p=(struct NodeDL *)(malloc(sizeof(struct NodeDL)));
    p->val=x;
    p->next=p->prev=NULL;
    return p;
}
// cautare un nod cu o anumita cheie
struct NodeDL* search1(struct list_header *L, int givenKey)
{
    struct NodeDL *p=L->first;
    while(p->val!=givenKey && p!=NULL)
    {
        p=p->next;
    }
    if(p->val==givenKey)
        return p;
    else if(p==NULL)
        return NULL;
}
//inserare la inceputul listei
void insert_first(struct list_header *L, int givenKey)
{
    struct NodeDL *p=createNod(givenKey);
    p->prev=NULL;
    p->next=L->first;

    if(L->first==L->last && L->last==NULL)
    {
        L->first=p;
        L->last=p;
    }
    else if(L->first==NULL)
    {
        L->last=p;
    }
    else
    {
        L->first->prev=p;
    }
    L->first=p;

}
// inserare la finalul listei
void insert_last(struct list_header *L, int givenKey)
{
    struct NodeDL *p=createNod(givenKey);
    p->prev=L->last;
    p->next=NULL;

    if(L->first==L->last && L->last==NULL)
    {
        L->first=p;
        L->last=p;
    }
    else if(L->last==NULL)
    {
        L->first=p;
    }
    else
    {
        L->last->next=p;
    }

    L->last=p;

}
// inserare dupa o anumita valoare
void insert_after_key(struct list_header *L, int afterKey, int givenKey)
{
    struct NodeDL *p=createNod(givenKey);
    struct NodeDL *q=L->first;
    while(q->val!=afterKey)
        q=q->next;
    if(q->val==afterKey)
    {
        struct NodeDL *r=q->next;
        q->next=p;
        p->prev=q;
        p->next=r;
        r->prev=p;
    }
}
// stergere primul element
void delete_first(struct list_header *L)
{
    struct NodeDL *p=L->first;
    L->first=L->first->next;
    free(p);

}
// stergere ultimul element
void delete_last(struct list_header *L)
{
    struct NodeDL *p=L->last;
    L->last=L->last->prev;
    free(p);
    L->last->next=NULL;

}
// stergere un nod cu o anumita cheie
void delete_key(struct list_header *L,int givenKey)
{
    struct NodeDL *p=L->first;
    while(p->next->val!=givenKey)
        p=p->next;
    if(p->next->val==givenKey)
    {
        struct NodeDL *victima=p->next;
        struct NodeDL *q=p->next->next;

        free(victima);
        p->next=q;
        q->prev=p;
    }
}
// afisare in fata
void print_forward(struct list_header *L)
{
    struct NodeDL *p=L->first;
    while(p!=NULL)
    {
        printf("%d ",p->val);
        p=p->next;
    }
    printf("\n");
}
// afisare in spate
void print_backward(struct list_header *L)
{
    struct NodeDL *p=L->last;
    while(p!=L->first)
    {
        printf("%d ",p->val);
        p=p->prev;
    }
    printf("\n");
}
