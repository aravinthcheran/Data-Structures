#include <stdio.h>
#include <stdlib.h>

// Structure for a graph node
struct Node {
    int data;
    struct Node* next;
};

// Structure for a graph
struct Graph {
    int V; // Number of vertices
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
    // Add edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // Add edge from dest to src (for undirected graph)
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Function to perform Breadth-First Search (BFS)
void BFS(struct Graph* graph, int start) {
    int V = graph->V;

    // Create an array to keep track of visited vertices
    int* visited = (int*)malloc(V * sizeof(int));
    for (int i = 0; i < V; ++i)
        visited[i] = 0;

    // Create a queue for BFS
    int* queue = (int*)malloc(V * sizeof(int));
    int front = 0, rear = 0;

    // Enqueue the starting vertex and mark it as visited
    queue[rear++] = start;
    visited[start] = 1;

    // Perform BFS
    while (front < rear) {
        // Dequeue a vertex and print it
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        // Traverse adjacent vertices
        struct Node* temp = graph->adjList[currentVertex];
        while (temp != NULL) {
            int adjacentVertex = temp->data;
            if (!visited[adjacentVertex]) {
                // Enqueue the adjacent vertex and mark it as visited
                queue[rear++] = adjacentVertex;
                visited[adjacentVertex] = 1;
            }
            temp = temp->next;
        }
    }

    free(visited);
    free(queue);
}

// Recursive function to perform Depth-First Search (DFS)
void DFSUtil(struct Graph* graph, int v, int* visited) {
    // Mark the current node as visited and print it
    visited[v] = 1;
    printf("%d ", v);

    // Recur for all the adjacent vertices
    struct Node* temp = graph->adjList[v];
    while (temp != NULL) {
        int adjacentVertex = temp->data;
        if (!visited[adjacentVertex]) {
            DFSUtil(graph, adjacentVertex, visited);
        }
        temp = temp->next;
    }
}

// Function to perform Depth-First Search (DFS)
void DFS(struct Graph* graph, int start) {
    int V = graph->V;

    // Create an array to keep track of visited vertices
    int* visited = (int*)malloc(V * sizeof(int));
    for (int i = 0; i < V; ++i)
        visited[i] = 0;

    // Perform DFS starting from the given vertex
    DFSUtil(graph, start, visited);

    free(visited);
}

// Example usage
int main() {
    int V = 6;
    struct Graph* graph = createGraph(V);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);

    printf("BFS starting from vertex 0: ");
    BFS(graph, 0);
    printf("\n");

    printf("DFS starting from vertex 0: ");
    DFS(graph, 0);
    printf("\n");

    return 0;
}