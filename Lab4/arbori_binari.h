#ifndef ARBORI_BINARI_H_INCLUDED
#define ARBORI_BINARI_H_INCLUDED

struct NodeT{

    int id;
    NodeT *left;
    NodeT *right;
};


NodeT *createBinTreeFromFile(FILE* f);
// afisari
void preorder(NodeT *p);
void inorder(NodeT *p);
void postorder(NodeT *p);
//inserari si stergeri
void insertLeft(NodeT* &p,int value,int x);
void insertRight(NodeT* &p,int value,int x);
void deleteNod(NodeT* &p,int value);
void deleteTree(NodeT* &p);
// alte functii
int leaf_node(NodeT *p);
int nr_intern_nodes(NodeT *p);
int height(NodeT *p);
int depth(NodeT *p);
int diameter(NodeT *p);
// cautare
NodeT *searc(NodeT *p,int key);

//functii ajutatoare
NodeT *generateParent(NodeT *p,int x); //returneaza parintele nodului cu valoarea x
int nr_total_nodes(NodeT *p);  // returneaza nr total de noturi ale arborelui binar


#endif // ARBORI_BINARI_H_INCLUDED
