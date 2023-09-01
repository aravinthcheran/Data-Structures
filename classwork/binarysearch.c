#include"binsearch.h"
int main()
{
    printf("Enter the elemnts");
    int n;
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements in ascending order:");
    for(int i=0;i<n;i++)
    {
        scanf("%d\n",&arr[i]);
    }
    printf("Enter the element to be found:");
    int num;
    scanf("%d",&num);
    int location = binsearch(num, arr, n);

    if (location != -1) {
        printf("The location is: %d\n", location);
    } else {
        printf("The element is not found!\n");
    }

}