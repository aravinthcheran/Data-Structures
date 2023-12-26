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
    return (h1 > h2) ? h1 : h2;
}

    //Finding Height
int FindHeight(struct node *node)
{
    return (node == NULL) ? 0 : node->height;
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

struct node* deleteNode(struct node* root, int key)
{
    // Step 1: Perform standard BST delete
    if (root == NULL)
        return root;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if(key > root->key)
        root->right = deleteNode(root->right, key);
    else
    {
        // node with only one child or no child
        if( (root->left == NULL) || (root->right == NULL) )
        {
            struct node *temp = root->left ? root->left : root->right;

            // No child case
            if(temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // One child case
             *root = *temp; // Copy the contents of the non-empty child

            free(temp);
        }
        else
        {
            // node with two children: Get the inorder
            // successor (smallest in the right subtree)
            struct node* temp = minValueNode(root->right);

            // Copy the inorder successor's data to this node
            root->key = temp->key;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->key);
        }
    }

    // If the tree had only one node then return
    if (root == NULL)
      return root;

    // Step 2: Update the height of the current node
    root->height = 1 + max(height(root->left), height(root->right));

    // Step 3: Get the balance factor
    int balance = getBalance(root);

    // Step 4: If the node is unbalanced, then try out the 4 cases
    // Case 1: Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Case 2: Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Case 3: Left Right Case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }

    // Case 4: Right Left Case
    if (balance < -1 && getBalance(root->right) > 0)
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