#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct graph{
    int v;
    struct node **list;
};

struct node* createNode(int data){
    struct node *newNode=malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

struct graph *createGraph(int v){
    struct graph *newGraph=malloc(sizeof(struct graph));
    newGraph->v=v;
    newGraph->list=malloc(v*sizeof(struct node *));
    for(int i=0;i<v;i++){
        newGraph->list[i]=createNode(i);
    }
    return newGraph;
}

void insert(struct graph *g, int u, int v){
    struct node *temp=g->list[u];
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=createNode(v);
}

void display(struct graph *g) {
    for(int i = 0; i < g->v; i++) {
        struct node *temp = g->list[i];
        printf("Adjacency list of vertex %d:\n", i);
        while(temp) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main(){
    printf("Enter the no of vertex:");
    int vertex;
    scanf("%d",&vertex);
    struct graph *g = createGraph(vertex);
    printf("Enter the no of edges:");
    int e;
    scanf("%d",&e);
    for(int i=0;i<e;i++){
        printf("Enter the pairs:");
        int u,v;
        scanf("%d %d",&u,&v);
        insert(g, u, v);
        insert(g, v, u);
    }
    display(g);
    return 0;
}