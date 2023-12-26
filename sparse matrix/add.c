#include<stdio.h>
#include<stdlib.h>

struct element{
    int row;
    int column;
    int data;
};

struct sparse{
    int totalrows;
    int totalcolumns;
    int totalelements;
    struct element *e;
};

struct element *getelement(int row, int column,int data){
    struct element *p=(struct element*)malloc(sizeof(struct element));
    p->row=row;
    p->column=column;
    p->data=data;
    return p;
}

struct sparse *getsparse(int tr, int tc, int te){
    struct sparse *s=(struct sparse*)malloc(sizeof(struct sparse));
    s->totalrows=tr;
    s->totalcolumns=tc;
    s->totalelements=te;
    s->e=(struct element*)malloc(te*sizeof(struct element));
    return s;
}

void displaysparse(struct sparse *s){
    struct sparse *temp=s;
    for(int i=0;i<temp->totalrows;i++){
        for(int j=0;j<temp->totalcolumns;j++){
            if(temp->e->row==i && temp->e->column==j){
                printf("%d ",temp->e->data);
                temp->e++;
            }
            else{
                printf("0 ");
            }
            
        }
        printf("\n");
    }
}

int main(){
    struct sparse *s=getsparse(5,5,5);
    s->e[0]=*getelement(0,0,1);
    s->e[1]=*getelement(1,1,2);
    s->e[2]=*getelement(2,2,3);
    s->e[3]=*getelement(3,3,4);
    s->e[4]=*getelement(4,4,5);
    displaysparse(s);
    return 0;
}