#ifndef LISTE_DUBLU_INLANTUITE_H_INCLUDED
#define LISTE_DUBLU_INLANTUITE_H_INCLUDED

struct NodeDL
{
    int val;
    struct NodeDL *next;
    struct NodeDL *prev;
};
struct list_header{

    struct NodeDL *first;
    struct NodeDL *last;
};

//alocare
void initList(struct list_header* L);
struct NodeDL *aloc(int x);
//search
struct NodeDL* search1(struct list_header *L, int givenKey);
//inserare
void insert_first(struct list_header *L, int givenKey);
void insert_last(struct list_header *L, int givenKey);
void insert_after_key(struct list_header *L, int afterKey, int givenKey);
//stergere
void delete_first(struct list_header *L);
void delete_last(struct list_header *L);
void delete_key(struct list_header *L,int givenKey);

//parcurgere
void print_forward(struct list_header *L);
void print_backward(struct list_header *L);

#endif // LISTE_DUBLU_INLANTUITE_H_INCLUDED
