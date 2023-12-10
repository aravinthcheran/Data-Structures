#include<stdio.h>
#include<stdlib.h>

struct Node{
    int key;
    int height;
    struct Node *left;
    struct Node *right;
};

int height(struct Node *n){
    if(n==NULL)return 0;
    return n->height;
}

int balancefactor(struct Node *n){
    if(n==NULL)return 0;
    return height(n->left)-height(n->right);
}

struct Node *leftrotate(struct Node *n){
    struct Node *x = n->right;
    struct Node *T2 = x->left;

    // Perform rotation
    x->left = n;
    n->right = T2;

    // Update heights
    n->height = 1 + (n->left ? n->left->height : 0);
    x->height = 1 + (x->left ? x->left->height : 0);

    // Return the new root
    return x;

}

struct Node* rightrotate(struct Node *x) {
    struct Node *y = x->left;
    struct Node *T2 = y->right;

    // Perform rotation
    y->right = x;
    x->left = T2;

    // Update heights
    x->height = 1 + (x->left ? x->left->height : 0);
    y->height = 1 + (y->right ? y->right->height : 0);

    // Return the new root
    return y;
}

struct Node* getNode(int key) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->key   = key;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;  // new Node is initially added at leaf
    return(node);
}

struct Node *insert()