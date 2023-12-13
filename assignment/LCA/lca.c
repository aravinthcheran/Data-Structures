#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* search(struct TreeNode* root, int val) {
    if (root == NULL || root->val == val) {
        return root;
    }
    
    if (val < root->val) {
        return search(root->left, val);
    } else {
        return search(root->right, val);
    }
}


// Function to insert a node into the binary tree
struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL) {
        return newNode(val);
    }

    if (val < root->val) {
        root->left = insert(root->left, val);
    } else if (val > root->val) {
        root->right = insert(root->right, val);
    }

    return root;
}

// Function to find the lowest common ancestor in a binary tree
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root == p || root == q || root == NULL) {
        return root;
    }

    struct TreeNode* leftResult = lowestCommonAncestor(root->left, p, q);
    struct TreeNode* rightResult = lowestCommonAncestor(root->right, p, q);

    if (leftResult != NULL && rightResult != NULL) {
        return root;
    }

    return (leftResult != NULL) ? leftResult : rightResult;
}

double calculateRuntime(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    // Perform the operation for which you want to measure the runtime
    struct TreeNode* ancestor = lowestCommonAncestor(root, p, q);

    clock_gettime(CLOCK_MONOTONIC, &end);

    double elapsedTime = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
    return elapsedTime;
}

int main() {
    FILE *fp;

    // Open the CSV file to save the average runtimes
    fp = fopen("average_runtimes.csv", "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    fprintf(fp, "Test Case,Average Runtime\n");

    int numIterations = 1000;  // Change this to the desired number of iterations

    // Run multiple test cases to calculate the average runtime for each determination of the common ancestor
    for (int i = 0; i < numIterations; i++) {
        // Create a binary tree with 500 elements
        struct TreeNode* root = NULL;
        for (int j = 0; j < 500; j++) {
            int val = rand() % 1000; // Random integers between 0 to 999
            if (j == 0) {
                root = newNode(val);
            } else {
                insert(root, val);
            }
        }

        // Generate random elements in the tree
        int randVal1 = rand() % 1000;
        int randVal2 = rand() % 1000;

        // Find the lowest common ancestor for the random elements
        double totalRuntime = 0.0;
        int numTests = 100;  // Change this to the desired number of tests per iteration
        for (int k = 0; k < numTests; k++) {
            struct TreeNode* node1 = search(root, randVal1);
            struct TreeNode* node2 = search(root, randVal2);
            double runtime = calculateRuntime(root, node1, node2);
            totalRuntime += runtime;
        }

        // Calculate the average runtime for the current test case
        double averageRuntime = totalRuntime / numTests;

        // Save average runtime to the CSV file for each test case
        fprintf(fp, "%d,%f\n", i + 1, averageRuntime);
    }

    fclose(fp); // Close the CSV file

    return 0;
}
