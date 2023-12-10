#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void perculateupmin(int *a, int i) {
    int parent = (i - 1) / 2;
    if (a[parent] > a[i]) {
        int temp = a[parent];
        a[parent] = a[i];
        a[i] = temp;
        perculateupmin(a, parent);
    }
}
void perculateupmax(int *a, int i) {
    int parent = (i - 1) / 2;
    if (a[parent] < a[i]) {
        int temp = a[parent];
        a[parent] = a[i];
        a[i] = temp;
        perculateupmax(a, parent);
    }
}

void display(int *a,int n){
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}

void deletemin(int *a, int i) {
    if (a[i] == 0) return;  // heap is empty

    if (a[2*i+1] == 0 && a[2*i+2] == 0) {
        a[i] = 0;
    } else if (a[2*i+1] == 0) {
        a[i] = a[2*i+2];
        deletemin(a, 2*i+2);
    } else if (a[2*i+2] == 0) {
        a[i] = a[2*i+1];
        deletemin(a, 2*i+1);
    } else {
        if (a[2*i+1] > a[2*i+2]) {
            a[i] = a[2*i+2];
            deletemin(a, 2*i+2);
        } else {
            a[i] = a[2*i+1];
            deletemin(a, 2*i+1);
        }
    }
}

int main(){
    int n;
    printf("Enter the no of levels:");
    scanf("%d",&n);
    int *a=(int*)calloc((pow(2,n+1)-1),sizeof(int));
    for(int i=0;i<(pow(2,n+1)-1);i++){
        printf("Enter the element:");
        scanf("%d",&a[i]);
        perculateupmax(a,i);
    }
    display(a,pow(2,n+1)-1);
}