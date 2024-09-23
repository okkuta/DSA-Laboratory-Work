#include<stdio.h>
#include<stdlib.h>

#define M 7
#define c1 1
#define c2 1

// verificare polinomiala

struct NodeT
{

    int key;
    NodeT *next;
};
int hash_prim(int key)
{
    return key%M;
}
int hashh(int key,int i)
{
    return (hash_prim(key)+c1*i+c2*i*i)%M;
}
void insertElement(NodeT* hTable[M], int key)
{
    int i=0;
    int index=hashh(key,i);
    while(hTable[index]!=NULL && hTable[index]->key!=key)
    {
        i++;
        index=hashh(key,i);
    }


    NodeT *nod=(NodeT *)(malloc(sizeof(NodeT)));
    nod->key=key;
    nod->next=NULL;
    if(hTable[index]==NULL)
        hTable[index]=nod;
    else
    {
        NodeT *p=hTable[index];
        while(p->next!=NULL)
            p=p->next;
        p->next=nod;
    }
}
NodeT* findElement(NodeT* hTable[M], int key)
{
    int i=0;
    int index=hashh(key,i);
    while(hTable[index]!=NULL && hTable[index]->key!=key)
    {
        i++;
        index=hashh(key,i);
    }
    NodeT *p=hTable[index];

    while(p!=NULL)
    {
        if(p->key==key)
            return p;
        p=p->next;
    }
    return NULL;
}
void deleteElement(NodeT* hTable[M], int key)
{
    int i=0;
    int index=hashh(key,i);
    while(hTable[index]!=NULL && hTable[index]->key!=key)
    {
        i++;
        index=hashh(key,i);
    }


    NodeT *v = hTable[index];  // victima
    NodeT *p = NULL; // tinem minte nodul precedent

    while (v!=NULL && v->key!=key)
    {
        p=v;
        v=v->next;
    }
    if (v==NULL)
    {
        printf("Elementul nu a fost gasit");
        return;
    }
    if (p==NULL)
    {
        hTable[index] =v->next;
    }
    else
    {
        p->next=v->next;
    }
    free(v);
}
void afisLista(NodeT *head)
{
    NodeT *p=head;
    while(p!=NULL)
    {
        printf("%d ",p->key);
        p=p->next;
    }
}
void afisTable(NodeT *hTable[M])
{
    for(int i=0; i<M; i++)
    {
        printf("Index %d: ",i);
        afisLista(hTable[i]);
        printf("\n");
    }
}
int main()
{
    NodeT *hTable[M]={NULL};

    insertElement(hTable,19);
    insertElement(hTable,36);
    insertElement(hTable,5);
    insertElement(hTable,21);
    insertElement(hTable,4);
    insertElement(hTable,26);
    insertElement(hTable,14);


    afisTable(hTable);

}
