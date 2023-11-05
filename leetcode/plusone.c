#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int i = 0;

    if (digits[digitsSize - 1] != 9) {
        digits[digitsSize - 1] += 1;
        *returnSize = digitsSize;
        return digits;
    }

    int num = 0,flag; // Change data type to long long int

    for (i = 0; i < digitsSize; i++) {
        long int num = num * 10 + digits[i];
        if(digits[i]!=9)
        {
            flag=1;
        }
    }
    printf("%d\n",num);
    num++;

    if (flag != 1) {
        digitsSize++;
    }

    int* returnarray = (int*)malloc(sizeof(int) * digitsSize);
    i = digitsSize - 1;

    while (num > 0) {
        int temp = num % 10;
        returnarray[i] = temp;
        num /= 10;
        i--;
    }

    *returnSize = digitsSize;
    return returnarray;
}


int main() {
    int digits[] ={9};
    int returnSize;
    
    int* result = plusOne(digits, sizeof(digits)/sizeof(int), &returnSize);

    // Print the result
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    // Free the dynamically allocated memory
    free(result);

    return 0;
}
