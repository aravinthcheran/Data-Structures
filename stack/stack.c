#include<stdio.h>
#include<stdlib.h>

int push(int *arr,int top,int n)
{
        if(top>=n-1)
        {
            printf("Stack Overflow\n");
            
        }
        else{
            printf("Enter the element to be pushed:");
            scanf("%d\n",&arr[++top]);
        }
        return top;
}


int pop(int *arr,int top,int n)
{
        if(top==-1)
        {
            printf("Stack Underflow\n");
        }
        else{
            printf("The element popped is %d\n",arr[top--]);
        }
    return top;
}
int main()
{
    int n;
    printf("Enter the size of the stack\n");
    scanf("%d",&n);
    int arr[n];
    int top=-1;
    while(1){
        printf("Enter your choice\n");
        printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
        int choice;
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                top=push(arr,top,n);
                break;
            case 2:
                top=pop(arr,top,n);
                break;
            case 3:
                if(top==-1)
                {
                    printf("Stack is empty\n");
                }
                else
                {
                    printf("The elements in the stack are\n");
                    for(int i=top;i>=0;i--)
                    {
                        printf("%d\n",arr[i]);
                    }
                    break;
                }

            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }
}