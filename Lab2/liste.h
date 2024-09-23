#ifndef LISTE_H_INCLUDED
#define LISTE_H_INCLUDED

struct NodeT
{
    int val;
    NodeT *next;
};


NodeT* search1(NodeT* first, int givenKey);
void insert_first(NodeT* & first, NodeT* & last, int givenKey);
void insert_last(NodeT* &first, NodeT* &last, int givenKey);
void insert_after_key(NodeT* &first, NodeT* &last, int afterKey, int givenKey);

void delete_first(NodeT* &first, NodeT* &last);
void delete_last(NodeT* &first, NodeT* &last);
void delete_key(NodeT* &first, NodeT* &last,int givenKey);


void afis(NodeT* first);
#endif // LISTE_H_INCLUDED
