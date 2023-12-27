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

void displaysparse(struct sparse *s) {
    int k = 0;
    for (int i = 0; i < s->totalrows; i++) {
        for (int j = 0; j < s->totalcolumns; j++) {
            if (k < s->totalelements && s->e[k].row == i && s->e[k].column == j) {
                printf("%d ", s->e[k].data);
                k++;
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}


struct sparse *addition(struct sparse *s1, struct sparse *s2){
    struct sparse *s3=(struct sparse*)malloc(sizeof(struct sparse));
    s3->totalrows=s1->totalrows;
    s3->totalcolumns=s1->totalcolumns;
    s3->totalelements=s1->totalelements+s2->totalelements;
    s3->e=(struct element*)malloc(s3->totalelements*sizeof(struct element));
    int i=0,j=0,k=0;
    while(i<s1->totalelements && j<s2->totalelements){
        if(s1->e[i].row<s2->e[j].row){
            s3->e[k++]=s1->e[i++];
        }
        else if(s1->e[i].row>s2->e[j].row){
            s3->e[k++]=s2->e[j++];
        }
        else{
            if(s1->e[i].column<s2->e[j].column){
                s3->e[k++]=s1->e[i++];
            }
            else if(s1->e[i].column>s2->e[j].column){
                s3->e[k++]=s2->e[j++];
            }
            else{
                s3->e[k]=s1->e[i];
                s3->e[k++].data=s1->e[i++].data+s2->e[j++].data;
            }
        }
    }
    for(;i<s1->totalelements;i++){
        s3->e[k++]=s1->e[i];
    }
    for(;j<s2->totalelements;j++){
        s3->e[k++]=s2->e[j];
    }
    return s3;

}

int main(){
    struct sparse *s=getsparse(5,5,5);
    s->e[0]=*getelement(0,0,1);
    s->e[1]=*getelement(1,1,2);
    s->e[2]=*getelement(2,2,3);
    s->e[3]=*getelement(3,3,4);
    s->e[4]=*getelement(4,4,5);
    displaysparse(s);
    printf("\n");
    struct sparse *s1=getsparse(5,5,5);
    s1->e[0]=*getelement(0,0,1);
    s1->e[1]=*getelement(1,1,2);
    s1->e[2]=*getelement(2,2,3);
    s1->e[3]=*getelement(3,3,4);
    s1->e[4]=*getelement(4,4,5);
    displaysparse(s1);
    printf("\n");
    struct sparse *s2=addition(s,s1);
    displaysparse(s2);
    return 0;
}