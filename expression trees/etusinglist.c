#include<stdio.h>
#include<stdlib.h>

struct treenode{
    char data;
    struct treenode *left;
    struct treenode *right;
};

struct treenode *getnode(char data){
    struct treenode *newnode=(struct treenode*)malloc(sizeof(struct treenode));
    newnode->data=data; 
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

int isop(char ch){
    return(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^');
}

struct treenode *createexpreesiontree(char postfix[]){
    struct treenode *stack[100];
    int top=-1;
    int i=0;
    while (postfix[i]!='\0')
    {
        if(isop(postfix[i])){
            struct treenode *newnode=getnode(postfix[i]);
            newnode->right=stack[top--];
            newnode->left=stack[top--];
            stack[++top]=newnode;
        }
        else{
            struct treenode *newnode=getnode(postfix[i]);
            stack[++top]=newnode;
        }
        i++;
    }
    return stack[top--];
}

void inordertraversal(struct treenode *root){
    if(root!=NULL){
        inordertraversal(root->left);
        printf("%c",root->data);
        inordertraversal(root->right);
    }
}

int evaluateexpression(struct treenode *node){
    if(node==NULL){
        return 0;
    }
    if(!isop(node->data)){
        return node->data-'0';
    }
    
    int lv=evaluateexpression(node->left);
    int rv=evaluateexpression(node->right);

    switch(node->data){
        case '+':return lv+rv;
        case '-':return lv-rv;
        case '*':return lv*rv;
        case '/':return lv/rv;
        case '^':return lv^rv;
        default:return 0;
    }
}

int main(){
    char postfix[100];
    printf("Enter the postfix expression: ");
    scanf("%s",postfix);
    struct treenode *root=createexpreesiontree(postfix);
    printf("Inorder traversal of the expression tree is: ");
    inordertraversal(root);
    printf("\n");
    printf("The value of the expression is: %d",evaluateexpression(root));
    return 0;
}