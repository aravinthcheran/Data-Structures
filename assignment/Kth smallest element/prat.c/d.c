#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the TreeNode structure
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxi(int node1,int node2)
{
    if(node1>node2)
    {
        return node1;
    }
    else
    {
        return node2;
    }
}
int diameter(struct TreeNode *root, int *d)
{
    if(root==NULL)
    {
        return 0;
    }
    int leftdepth=diameter(root->left,d);
    int rightdepth=diameter(root->right,d);
    int depth=leftdepth+rightdepth;
    *d=maxi(*d,depth);
    int maximum=maxi(leftdepth,rightdepth);
    return maximum+1;
}
int diameterOfBinaryTree(struct TreeNode* root){
    if (root==NULL)
    {
        return 0;
    }
    int d=0;
    diameter(root,&d);
    return d;
}

// Function to create a new TreeNode
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Function to generate a random binary tree of given size
struct TreeNode* generateRandomTree(int size) {
    if (size <= 0) {
        return NULL;
    }

    struct TreeNode* root = newNode(rand() % 100); // Random node value between 0 and 99

    int leftSize = rand() % size;
    int rightSize = size - 1 - leftSize; // -1 for the root

    root->left = generateRandomTree(leftSize);
    root->right = generateRandomTree(rightSize);

    return root;
}

// Function to calculate the runtime for each tree
double measureRuntime(struct TreeNode* root) {
    clock_t start = clock();
    int result = diameterOfBinaryTree(root);
    clock_t end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

int main() {
    srand(time(NULL));

    FILE *fp = fopen("tree_runtimes.csv", "w");
    if (fp == NULL) {
        printf("Error opening file!");
        return 1;
    }

    fprintf(fp, "Tree_Size,Runtime\n");

    // Generating 1000 random trees with varying sizes up to 100,000 nodes
    for (int i = 0; i < 1000; ++i) {
        int size = rand() % 100000 + 1; // Random tree size between 1 and 100,000

        // Generating a random tree of size 'size'
        struct TreeNode* root = generateRandomTree(size);

        // Measuring runtime
        double runtime = measureRuntime(root);

        // Writing data to CSV
        fprintf(fp, "%d,%.6f\n", size, runtime);

        // Free memory allocated for tree nodes
        // (assuming no memory leak by freeing the entire tree structure)
        free(root);
    }

    fclose(fp);
    return 0;
}
