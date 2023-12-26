#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct list{
    struct node *head;
};

struct node* createNode(int data){
    struct node *newNode=malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

struct list* createList(){
    struct list *newList=malloc(sizeof(struct list));
    newList->head=NULL;
    return newList;
}

void display(struct list *adjList[], int v) {
    for(int i = 0; i < v; i++) {
        struct node *temp = adjList[i]->head;
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
    struct list *adjList[vertex];
    for(int i=0;i<vertex;i++){
        adjList[i]=createList();
    }
    printf("Enter the no of edges:");
    int e;
    scanf("%d",&e);
    for(int i=0;i<e;i++){
        printf("Enter the pairs:");
        int u,v;
        scanf("%d %d",&u,&v);
        if(adjList[u]->head==NULL){
            adjList[u]->head=createNode(u);
        }
        struct node *temp=adjList[u]->head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=createNode(v);
        if(adjList[v]->head==NULL){
        adjList[v]->head=createNode(v);
        }
        temp=adjList[v]->head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=createNode(u);
    }
    display(adjList,vertex);
}