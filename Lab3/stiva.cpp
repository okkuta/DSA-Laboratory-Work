#include<stdio.h>
#include<stdlib.h>

struct NodeT
{
    int val;
    NodeT *next;
};
//am scris "stac" deoarece "stack" e cuvant rezervat in C++
void afis(NodeT *stac)
{
    NodeT *p=stac;
    while(p!=NULL)
    {
        printf("%d\n",p->val);
        p=p->next;
    }
}
void push(NodeT* &stac, int key)    //insert_first
{

    NodeT *p= ( NodeT * )malloc(sizeof(NodeT));
    p->val=key;
    p->next=NULL;

    p->next=stac;
    stac=p;
}
void pop(NodeT* &stac)  // delete_first
{
    NodeT *p=stac;
    stac=stac->next;
    free(p);
}
int main()
{
    NodeT *stac=NULL;
    push(stac,5);
    push(stac,4);
    push(stac,3);
    push(stac,2);
    pop(stac);
    push(stac,1);
    push(stac,0);
    pop(stac);
    afis(stac);

}
