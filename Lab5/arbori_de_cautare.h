#ifndef ARBORI_DE_CAUTARE_H_INCLUDED
#define ARBORI_DE_CAUTARE_H_INCLUDED

struct NodeT{

    int id;
    NodeT *left;
    NodeT *right;
    NodeT *parinte;
};

NodeT* insertNode( NodeT *root, int key );
void preorder(NodeT *p);
void inorder(NodeT *p);
void postorder(NodeT *p);
NodeT* findMin(NodeT *root);
NodeT* findMax(NodeT *root);
NodeT *searchKey(NodeT *root,int key);

NodeT* predecesor(NodeT *root,int key);
NodeT* succesor(NodeT *root,int key);
NodeT* deleteNode(NodeT* root, int key);

#endif // ARBORI_DE_CAUTARE_H_INCLUDED
