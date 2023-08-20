#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "swap.h"

void fisheryates(int *arr, int n, int start, int end)
{
    srand(time(NULL));
    for (int i = end - 2; i >= start-1; i--)
    {
        int j = start-1 + rand() % (end - start+1);
        swap(&arr[i], &arr[j]);
    }
}

