#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int maxheap(int *a,int i){
    if(i==0){
        return 1;
    }
    int parent=(i-1)/2;
    if(a[parent]<a[i]){
        return 0;
    }
    else{
        return maxheap(a,i-1);
    }
}


int main(){
    int n;
    printf("Enter the no of levels:");
    scanf("%d",&n);
    int *a=(int*)calloc((pow(2,n)-1),sizeof(int));
    for(int i=0;i<(pow(2,n)-1);i++){
        printf("Enter the element:");
        scanf("%d",&a[i]);
    }
    if(maxheap(a,(pow(2,n)-1))==1)printf("Tree is maxheap:");
    else printf("Tree is not a maxheap");
}