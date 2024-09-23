#include<stdio.h>
#include<stdlib.h>
//am scris coada deoarece queue e cuvant rezervat in C++
struct coada
{
    int val;
    coada *next;
};
// creare nod nou
coada *createNod(int x)
{
    coada *p=(coada *)(malloc(sizeof(coada)));
    p->next=NULL;
    p->val=x;

    return p;
}
//adaugare la sfarsit
void enqueue(coada* &my_queue, int key)
{
    coada *p=createNod(key);
    coada *q=my_queue;
    if(q==NULL)
    {
        my_queue=p;

    }
    else
    {
        while(q->next!=NULL)
            q=q->next;

        q->next=p;
    }
}
// stergerea primului element
int dequeue(coada* &my_queue)
{
    coada *p=my_queue->next;
    int x=my_queue->val;
    free(my_queue);
    my_queue=p;

    return x;
}
//afisare coada
void parcurgere(coada *my_queue)
{
    coada *p=my_queue;
    while(p!=NULL)
    {
        printf("%d ",p->val);
        p=p->next;
    }
    printf("\n");
}
int main()
{
    coada *l=(coada *)(malloc(sizeof(coada)));
    l=NULL;
    enqueue(l,1);
    enqueue(l,2);
    enqueue(l,3);
    enqueue(l,4);
    enqueue(l,5);

    parcurgere(l);
    printf("%d\n",dequeue(l));
    parcurgere(l);
}
