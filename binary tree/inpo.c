#include <stdio.h>
#include <stdlib.h>

// Define a structure for a BST node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to search for an element's index in inorder traversal
int search(int arr[], int start, int end, int value) {
    int i;
    for (i = start; i <= end; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

// Function to construct BST from inorder and postorder traversals
struct Node* buildUtil(int in[], int post[], int inStart, int inEnd, int* postIndex) {
    if (inStart > inEnd) {
        return NULL;
    }

    struct Node* node = newNode(post[*postIndex]);
    (*postIndex)--;

    if (inStart == inEnd) {
        return node;
    }

    int inIndex = search(in, inStart, inEnd, node->data);

    node->right = buildUtil(in, post, inIndex + 1, inEnd, postIndex);
    node->left = buildUtil(in, post, inStart, inIndex - 1, postIndex);

    return node;
}

// Function to construct BST from inorder and postorder traversals
struct Node* buildTree(int in[], int post[], int n) {
    int postIndex = n - 1;
    return buildUtil(in, post, 0, n - 1, &postIndex);
}

// Function to perform inorder traversal of BST
void inorder1(struct Node* node) {
    if (node == NULL) {
        return;
    }
    inorder1(node->left);
    printf("%d ", node->data);
    inorder1(node->right);
}

int main() {
    // Example inorder and postorder traversals
    int inorder[] = { 4, 2, 5, 1, 6, 3 };
    int postorder[] = { 4, 5, 2, 6, 3, 1 };
    int n = sizeof(inorder) / sizeof(inorder[0]);

    // Constructing the BST
    struct Node* root = buildTree(inorder, postorder, n);

    // Print the inorder traversal of the constructed BST
    printf("Inorder traversal of the constructed BST is: \n");
    inorder1(root);
    printf("\n");

    return 0;
}


User
generate bst bst from inorder and postorder in c
ChatGPT
Sure, here's an example of how you can create a Binary Search Tree (BST) from its inorder and postorder traversals in C:

c
Copy code
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a BST node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to search for an element's index in inorder traversal
int search(int arr[], int start, int end, int value) {
    int i;
    for (i = start; i <= end; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

// Function to construct BST from inorder and postorder traversals
struct Node* buildUtil(int in[], int post[], int inStart, int inEnd, int* postIndex) {
    if (inStart > inEnd) {
        return NULL;
    }

    struct Node* node = newNode(post[*postIndex]);
    (*postIndex)--;

    if (inStart == inEnd) {
        return node;
    }

    int inIndex = search(in, inStart, inEnd, node->data);

    node->right = buildUtil(in, post, inIndex + 1, inEnd, postIndex);
    node->left = buildUtil(in, post, inStart, inIndex - 1, postIndex);

    return node;
}

// Function to construct BST from inorder and postorder traversals
struct Node* buildTree(int in[], int post[], int n) {
    int postIndex = n - 1;
    return buildUtil(in, post, 0, n - 1, &postIndex);
}

// Function to perform inorder traversal of BST
void inorder(struct Node* node) {
    if (node == NULL) {
        return;
    }
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

int main() {
    // Example inorder and postorder traversals
    int inorder[] = { 4, 2, 5, 1, 6, 3 };
    int postorder[] = { 4, 5, 2, 6, 3, 1 };
    int n = sizeof(inorder) / sizeof(inorder[0]);

    // Constructing the BST
    struct Node* root = buildTree(inorder, postorder, n);

    // Print the inorder traversal of the constructed BST
    printf("Inorder traversal of the constructed BST is: \n");
    inorder(root);
    printf("\n");

    return 0;
}
Replace the inorder and postorder arrays in the main function with your own inorder and postorder traversals respectively to generate the Binary Search Tree (BST) accordingly.

This code first constructs the BST using the given inorder and postorder traversals and then performs an inorder traversal to display the elements of the constructed BST.

User
frompreorder and inorder
ChatGPT
Certainly! Here's an example of how to create a Binary Search Tree (BST) from its preorder and inorder traversals in C:

c
Copy code
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a BST node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to search for an element's index in inorder traversal
int search(int arr[], int start, int end, int value) {
    int i;
    for (i = start; i <= end; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

// Function to construct BST from preorder and inorder traversals
struct Node* buildUtil(int pre[], int in[], int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd) {
        return NULL;
    }

    struct Node* node = newNode(pre[*preIndex]);
    (*preIndex)++;

    if (inStart == inEnd) {
        return node;
    }

    int inIndex = search(in, inStart, inEnd, node->data);

    node->left = buildUtil(pre, in, inStart, inIndex - 1, preIndex);
    node->right = buildUtil(pre, in, inIndex + 1, inEnd, preIndex);

    return node;
}

// Function to construct BST from preorder and inorder traversals
struct Node* buildTree(int pre[], int in[], int n) {
    int preIndex = 0;
    return buildUtil(pre, in, 0, n - 1, &preIndex);
}