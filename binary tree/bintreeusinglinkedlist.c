#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left,*right;
};

struct node *getnode(int data){
    struct node *p=malloc(sizeof(struct node));
    p->data=data;
    p->left=NULL;
    p->right=NULL;
    return p;
}

/*void insert(struct node **root){
    for(int i=0;i<elements;i++){
        int data;
        printf("Enter the data:");
        scanf("%d",&data);
        struct node *newnode=getnode(data);
        struct node *temp=*root;
        struct node *parent=*root;
        int j=0;
        while(1){
            if(*temp==NULL){
                temp=newnode;
                break;
            }
            else if((*root)->data<data){
                temp=temp->right;
            }
            else{
                temp=temp->left;
            }
        }
    }
}*/

void insert(struct node **root, int data) {
    struct node *newnode = getnode(data);
    
    if (*root == NULL) {
        *root = newnode;
    } else if (data > (*root)->data) {
        insert(&((*root)->right), data);
    } else {
        insert(&((*root)->left), data);
    }
}

void display(struct node *root){
    //inorder traversal
    if(root->left!=NULL){
        display(root->left);
    }
    printf("%d ",root->data);
    if(root->right!=NULL){
        display(root->right);
    }
}

struct node *search(struct node *parent, struct node *root, int data, int *lr) {
    if (root == NULL) {
        return NULL;
    }

    if (root->data == data) {
        return parent;
    } else if (data > root->data) {
        *lr = 1;
        return search(root, root->right, data, lr);
    } else {
        *lr = 0;
        return search(root, root->left, data, lr);
    }
}


int main()
{
    printf("Enter the no of elements:");
    int elements,lr=2;
    scanf("%d",&elements);
    struct node *root=NULL;
    for(int i=0;i<elements;i++){
        int data;
        printf("Enter the data:");
        scanf("%d",&data);
        insert(&root,data);
    }
    display(root);
    struct node*parent=search(root,root,5,&lr);
    printf("%d",parent->data);
}