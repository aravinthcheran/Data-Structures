#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// Structure for a graph node
struct Node {
    int data;
    struct Node* next;
};

// Structure for a directed graph
struct Graph {
    int V;          // Number of vertices
    struct Node** adjList; // Adjacency adjList
};

// Function to create a new graph node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adjList = (struct Node**)malloc(V * sizeof(struct Node*)); // Fix: Change the type of adjList to struct Node**

    for (int i = 0; i < V; ++i)
        graph->adjList[i] = NULL;

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}

// Recursive function to perform topological sort
void topologicalSort(struct Graph* g) {
    int v = g->V;
    int* indegree = (int*)calloc(v, sizeof(int));
    int* stack = (int*)malloc(v * sizeof(int));
    int stackIndex = 0;

    // Calculate indegree of each vertex
    for (int i = 0; i < v; i++) {
        struct Node* temp = g->adjList[i];
        while (temp) {
            indegree[temp->data]++;
            temp = temp->next;
        }
    }

    // Add all vertices with indegree 0 to the stack
    for (int i = 0; i < v; i++) {
        if (indegree[i] == 0) {
            stack[stackIndex++] = i;
        }
    }

    // Process vertices in the stack
    while (stackIndex > 0) {
        // Pop a vertex from stack
        int u = stack[--stackIndex];

        // Print the popped vertex
        printf("%d ", u);

        // Decrease indegree of all vertices adjacent to the popped vertex
        struct Node* temp = g->adjList[u];
        while (temp) {
            indegree[temp->data]--;
            if (indegree[temp->data] == 0) {
                stack[stackIndex++] = temp->data;
            }
            temp = temp->next;
        }
    }

    free(indegree);
    free(stack);
}

// Example usage
int main() {
    int V = 7;
    struct Graph* graph = createGraph(V);

    addEdge(graph, 1, 2);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 4, 3);
    addEdge(graph, 4, 2);
    addEdge(graph, 2, 5);
    addEdge(graph, 2, 6);
    addEdge(graph, 5, 6);

    topologicalSort(graph);

    return 0;
}