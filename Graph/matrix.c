#include<stdio.h>
#include<stdlib.h>

struct graph{
    int edges, vertices;
    int **adj;
};

struct graph *construct(int edges,int vertices){
    struct graph *G=malloc(sizeof(struct graph));
    G->edges=edges;
    G->vertices=vertices;
    G->adj = malloc(vertices * sizeof(int *));
    for(int i = 0; i < vertices; i++) {
        G->adj[i] = calloc(vertices, sizeof(int));
    }
    for(int i=0;i<edges;i++){
        printf("Enter the pairs:");
        int u,v;
        scanf("%d %d",&u,&v);
        G->adj[u][v]=1;
        G->adj[v][u]=1;
    }
    return G;
}