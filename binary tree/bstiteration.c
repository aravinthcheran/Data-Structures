#include<stdio.h>
#include<stdlib.h>
#include<math.h>


void insert(int *a,int elements){
    for(int i=0;i<elements;i++){
        int data;
        printf("Enter the data:");
        scanf("%d",&data);
        int j=0;
        while(1){
            if(a[j]==0){
                a[j]=data;
                break;
            }
            else if(a[j]<data){
                j=2*j+2;
            }
            else{
                j=2*j+1;
            }
        }
    }
}

void display(int *a,int elements){
    for(int i=0;i<elements;i++){
        printf("%d ",*(a+i));
    }
}

int main(){
    printf("Enter the no of elements:");
    int elements;
    scanf("%d",&elements);
    int *a=(int*)calloc(pow(2,elements)-1,sizeof(int));
    insert(a,elements);
    display(a,pow(2,elements)-1);
}