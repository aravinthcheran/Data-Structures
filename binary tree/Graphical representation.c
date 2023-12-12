#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

void generateDotFile(Node* root, FILE* dotFile) {
    if (root == NULL) {
        return;
    }

    if (root->left != NULL) {
        fprintf(dotFile, "%d -> %d;\n", root->data, root->left->data);
        generateDotFile(root->left, dotFile);
    }

    if (root->right != NULL) {
        fprintf(dotFile, "%d -> %d;\n", root->data, root->right->data);
        generateDotFile(root->right, dotFile);
    }
}

int main() {
    Node* root = NULL;
    root = insert(root, 8);
    insert(root, 3);
    insert(root, 10);
    insert(root, 1);
    insert(root, 6);
    insert(root, 14);
    insert(root, 4);
    insert(root, 7);
    insert(root, 13);

    FILE* dotFile = fopen("binary_tree.dot", "w");
    if (dotFile == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fprintf(dotFile, "digraph BinarySearchTree {\n");
    generateDotFile(root, dotFile);
    fprintf(dotFile, "}\n");

    fclose(dotFile);

    system("dot -Tpng binary_tree.dot -o binary_tree.png");

    return 0;
}
