#include <stdio.h>
#include <stdlib.h>

// Structure for a graph node
struct Node {
    int data;
    struct Node* next;
};

// Structure for a directed graph
struct Graph {
    int V;          // Number of vertices
    struct Node** adjList; // Adjacency list
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
    graph->adjList = (struct Node*)malloc(V * sizeof(struct Node));

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
void topologicalSortUtil(struct Graph* graph, int v, int visited[], int stack[], int* stackIndex) {
    visited[v] = 1;

    struct Node* currentNode = graph->adjList[v];
    while (currentNode != NULL) {
        int adjacentVertex = currentNode->data;
        if (!visited[adjacentVertex]) {
            topologicalSortUtil(graph, adjacentVertex, visited, stack, stackIndex);
        }
        currentNode = currentNode->next;
    }

    stack[(*stackIndex)++] = v;
}

// Function to perform topological sort
void topologicalSort(struct Graph* graph) {
    int V = graph->V;
    int* visited = (int*)calloc(V, sizeof(int));
    int* stack = (int*)malloc(V * sizeof(int));
    int stackIndex = 0;

    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            topologicalSortUtil(graph, i, visited, stack, &stackIndex);
        }
    }

    // Print the topological order
    printf("Topological Sort: ");
    for (int i = stackIndex - 1; i >= 0; --i) {
        printf("%d ", stack[i]);
    }

    free(visited);
    free(stack);
}

// Example usage
int main() {
    int V = 6;
    struct Graph* graph = createGraph(V);

    addEdge(graph, 1, 2);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 4, 3);
    addEdge(graph, 4, 5);
    addEdge(graph, 2, 3);

    topologicalSort(graph);

    return 0;
}