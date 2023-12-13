#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void convert(struct TreeNode *root, int *sum) {
    if (root == NULL) {
        return;
    }

    convert(root->right, sum);

    *sum += root->val;
    root->val = *sum;

    convert(root->left, sum);
}

struct TreeNode* convertBST(struct TreeNode* root) {
    int sum = 0;
    convert(root, &sum);
    return root;
}

double calculateRuntime(struct TreeNode* root) {
    clock_t start, end;
    double cpu_time_used = 0.0;

    int numIterations = 100; // Adjust the number of iterations for better precision

    for (int i = 0; i < numIterations; i++) {
        start = clock();
        root = convertBST(root);
        end = clock();
        cpu_time_used += ((double) (end - start)) / CLOCKS_PER_SEC;
    }

    return cpu_time_used / numIterations; // Return average runtime
}


int main() {
    FILE *fp;
    srand(time(NULL));

    // Open the CSV file to save size and runtime
    fp = fopen("bst_runtimes.csv", "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    fprintf(fp, "Size,Runtime\n");

    int numTrees = 1000;

    // Generate 1000 BSTs with increasing sizes and measure the runtime for each
    for (int i = 1; i <= numTrees; i++) {
        struct TreeNode* root = NULL;
        int size = i * 10; // Increasing size (modify the multiplier as needed)

        // Build BST with increasing size
        for (int j = 0; j < size; j++) {
            int val = rand() % 1000; // Random integers between 0 to 999
            if (j == 0) {
                root = newNode(val);
            } else {
                struct TreeNode* newnode = newNode(val);
                struct TreeNode* current = root;
                struct TreeNode* parent = NULL;
                while (current != NULL) {
                    parent = current;
                    if (val < current->val) {
                        current = current->left;
                    } else {
                        current = current->right;
                    }
                }
                if (val < parent->val) {
                    parent->left = newnode;
                } else {
                    parent->right = newnode;
                }
            }
        }

        // Measure runtime and save data to CSV
        double runtime = calculateRuntime(root);
        fprintf(fp, "%d,%f\n", size, runtime);
    }

    fclose(fp); // Close the CSV file

    return 0;
}
