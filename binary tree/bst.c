#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void insert(int *a,int data,int index){
    if(a[index]==0){
        a[index]=data;
    }
    else if(data<a[index]){
        insert(a,data,2*index+1);
    }
    else{
        insert(a,data,2*index+2);
    }
}

void display(int *a,int index){
    if(*(a+2*i+1)!=0){
        display(a,2*i+1);
    }
    printf("%d",*(a+i));
    if(*(a+2*i+2)!=0){
        display(a,2*i+2);
    }
}

int search(int *a,int data,int index){
    if(data==a[index]){
        return index;
    }
    else if(data<a[index]){
        search(a,data,2*index+1);
    }
    else{
        search(a,data,2*index+2);
    }
    return -1;
}

void deletion(int *a,int data){
    if(search(data)==-1){
        printf("elemnt not found");
        return;
    }
    else{
        int index=search(data);
        if(*(a+2*index+1)==0 && *(a+2*index+2)==0){
            *(a+index)=0;
        }
        else if(*(a+2*index+1)!=0 && *(a+2*index+2)==0){
            *(a+index)=*(a+2*index+1);
            *(a+2*index+1)=0;
        }
        else if(*(a+2*index+1)==0 && *(a+2*index+2)!=0){
            *(a+index)=*(a+2*index+2);
            *(a+2*index+2)=0;
        }
        else{
            int temp=*(a+2*index+2);
            while(*(a+2*temp+1)!=0){
                temp=*(a+2*temp+1);
            }
            *(a+index)=*(a+temp);
            *(a+temp)=0;
        }
    }
}

int predecessor(int *a){
    int i=0;
    if(a[i+1]!=0){
        while(a[2*i+2]!=0){
            i=2*i+2;
        }
    }
    return a[i];
}

void deleteNode(int *a, int index, int key) {
    if (a[index] == 0) {
        return;
    } else if (a[index] > key) {
        deleteNode(a, 2 * index + 1, key);
    } else if (a[index] < key) {
        deleteNode(a, 2 * index + 2, key);
    } else {
        if (a[2 * index + 1] == 0) {
            a[index] = a[2 * index + 2];
            deleteNode(a, 2 * index + 2, a[2 * index + 2]);
        } else if (a[2 * index + 2] == 0) {
            // Node with only left child
            a[index] = a[2 * index + 1];
            deleteNode(a, 2 * index + 1, a[2 * index + 1]);
        } else {
            // Node with two children, replace with predecessor
            int temp = predecessor(a, 2 * index + 1);
            a[index] = temp;
            deleteNode(a, 2 * index + 1, temp);
        }
    }
}
void deletion(int *a,int data)
int main(){
    printf("Enter the no of elements:");
    int elements;
    scanf("%d",&elements);
    int *a=(int*)calloc(pow(2,elements)-1,sizeof(int));
    for(int i=0;i<elements;i++){
        printf("Enter the data:");
        int data;
        scanf("%d",&data);
        insert(a,data,0);
    }
    display(a,pow(2,elements)-1);
    search(a,5,0);
}
