#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* getnode(int data) {
    struct node* p = malloc(sizeof(struct node));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void insert(struct node** root, int data) {
    if (*root == NULL) {
        
        *root = getnode(data);
    } else if (data > (*root)->data) {
        insert(&((*root)->right), data);
    } else {
        insert(&((*root)->left), data);
    }
}

struct node* successor(struct node* node) {
    struct node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct node* predecessor(struct node* root) {
    struct node* current = root;
    while (current && current->right != NULL)
        current = current->right;
    return current;
}

void display(struct node* root) {
    if (root == NULL) {
        return;
    }
    display(root->left);
    printf("%d ", root->data);
    display(root->right);
}

struct node* search(struct node* parent, struct node* root, int data, int* side) {
    if (root == NULL) {
        return NULL;
    }

    if (root->data == data) {
        return parent;
    } else if (data > root->data) {
        *side = 1;
        return search(root, root->right, data, side);
    } else {
        *side = 0;
        return search(root, root->left, data, side);
    }
}

struct node* deleteNode(struct node* root, int key) {
    if (root == NULL) return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        else {
            struct node* temp = predecessor(root->left);
            root->data = temp->data;
            root->left = deleteNode(root->left, temp->data); 
        }
    }
    return root;
}
    

int main() {
    struct node* root = NULL;
    int elements;
    printf("Enter the number of elements: ");
    scanf("%d", &elements);
    for (int i = 0; i < elements; i++) {
        int data;
        printf("Enter the data: ");
        scanf("%d", &data);
        insert(&root, data);
    }
    printf("Binary Search Tree: ");
    display(root);
    printf("\n");
    int data;
    printf("Enter the data to be deleted: ");
    scanf("%d", &data);
    struct node *rt=deleteNode(root, data);
    printf("BST after deletion: ");
    display(rt);
    printf("\n");
    return 0;
}

// Enter the number of elements: 7
// Enter the data: 4
// Enter the data: 2
// Enter the data: 1
// Enter the data: 3
// Enter the data: 7
// Enter the data: 5
// Enter the data: 9