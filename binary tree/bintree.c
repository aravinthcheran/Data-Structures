#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void insert(int *a, int elements) {
    printf("Enter the data to be inserted: ");
    int data;
    scanf("%d", &data);
    for (int i = 0; i < elements; i++) {
        if (*(a + i) == 0) {
            *(a + i) = data;
            printf("Inserted successfully\n");
            return;
        }
    }
    printf("No space to insert\n");
}

void inorder(int *a, int index){
    if(*(a+2*index+1)!=0){
        inorder(a,2*index+1);
    }
    printf("%d ",*(a+index));
    if(*(a+2*index+2)!=0){
        inorder(a,2*index+2);
    }
}

void delete(int *a, int elements) {
    printf("Enter the data to be deleted: ");
    int data;
    scanf("%d", &data);
    for (int i = 0; i < elements; i++) {
        if (*(a + i) == data) {
            *(a + i) = 0;
            printf("Deleted successfully\n");
            return;
        }
    }
    printf("Element not found\n");
}

int main() {
    printf("Enter the number of levels: ");
    int levels;
    scanf("%d", &levels);
    int elements = pow(2, levels) + 1;
    int *a = (int *)calloc(elements, sizeof(int));
    if (a == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    while (1) {
        int choice;
        printf("1.Insert\n2.Display\n3.Delete\n4.Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insert(a, elements);
                break;
            case 2:
                inorder(a,0);
                printf("\n");
                break;
            case 3:
                delete(a, elements);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}
