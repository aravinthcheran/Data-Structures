#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    int height;
    struct node *left;
    struct node *right;
};

//Creating node:
struct node *createNode(int element)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = element;
    newnode->height = 1;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

    //Maximum height
int maxiHeight(int h1, int h2)
{
    if(h1>h2)
        return h1;
    else
        return h2;
}

    //Finding Height
int FindHeight(struct node *node)
{
    if (node==NULL)
        return 0;
    else
        return node->height;
}

    //finding BF
int GetBalance(struct node *ancestor)
{
    return FindHeight(ancestor->left)-FindHeight(ancestor->right);
}

    //left rotating
struct node *leftRotate(struct node *ancestor)
{
    struct node *child = ancestor->right;
    ancestor->right = child->left;
    child->left = ancestor;
    ancestor->height = maxiHeight(FindHeight(ancestor->left),FindHeight(ancestor->right))+1;
    child->height = maxiHeight(FindHeight(child->left),FindHeight(child->right))+1;
    return child;
}

    //right rotating
struct node *rightRotate(struct node *ancestor)
{
    struct node *child = ancestor->left;
    ancestor->left = child->right;
    child->right = ancestor;
    ancestor->height = maxiHeight(FindHeight(ancestor->left),FindHeight(ancestor->right))+1;
    child->height = maxiHeight(FindHeight(child->left),FindHeight(child->right))+1;
    return child;
}

    //inserting part:
struct node *Insert_AVL(struct node *root, int element)
{
    if (root == NULL)
    {
        return createNode(element);
    }

    if (element < root->data)
    {
        root->left = Insert_AVL(root->left, element);
    }
    else
    {
        root->right = Insert_AVL(root->right, element);
    }

    root->height = maxiHeight(FindHeight(root->left), FindHeight(root->right)) + 1;
    int balance = GetBalance(root);

    // Cases for rotation:
    //LL rotation
    if (balance > 1 && element < root->left->data)
    {
        return rightRotate(root);
    }
    //RR rotation
    else if (balance < -1 && element > root->right->data)
    {
        return leftRotate(root);
    }
    //LR rotation
    else if (balance > 1 && element > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    //RL rotation
    else if (balance < -1 && element < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

    //Inorder Traversal
void Inorder_display(struct node *root)
{
    if(root!=NULL)
    {
        Inorder_display(root->left);
        printf("%d ",root->data);
        Inorder_display(root->right);
    }
}
    //Preorder Traversal
void Preorder_display(struct node *root)
{
    if(root != NULL)
    {
        printf("%d ",root->data);
        Preorder_display(root->left);
        Preorder_display(root->right);
    }
}

    //Function for freeing memory:
void Free_root(struct node *root)
{
    if (root != NULL)
    {
        Free_root(root->left);
        Free_root(root->right);
        free(root);
    }
}

int main()
{
    int n,i,element;
    printf("Enter the number of elements to insert in AVL tree: ");
    scanf("%d",&n);
    struct node *root = NULL;
    for(i=0; i<n; i++)
    {
        printf("Enter data: ");
        scanf("%d",&element);
        root = Insert_AVL(root, element);
    }
    printf("Inorder display: ");
    Inorder_display(root);
    printf("\n");
    printf("Preorder display: ");
    Preorder_display(root);
    Free_root(root);
}