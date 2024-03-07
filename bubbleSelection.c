/*
    Carson Davie
    Lab 7
    Torosdagli
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct element
{
    int data;
    int numswaps;
} element;

element *bubbleSort(int arr[], int n)
{
    element *swaps = (element *)malloc(sizeof(element) * n);

    for (int k = 0; k < n; k++)
    {
        swaps[k].data = arr[k];
        swaps[k].numswaps = 0;
    }

    int temp;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            // swap elements next to each other
            if (swaps[j].data > swaps[j + 1].data)
            {
                temp = swaps[j].data;
                swaps[j].data = swaps[j + 1].data;
                swaps[j + 1].data = temp;

                for (int l = 0; l < n; l++)
                {
                    if (arr[l] == swaps[j].data || arr[l] == swaps[j + 1].data)
                        (swaps[l].numswaps)++;
                }
            }
        }
    }

    return swaps;
}

element *selectionSort(int arr[], int n)
{
    element *swaps = (element *)malloc(sizeof(element) * n);

    for (int k = 0; k < n; k++)
    {
        swaps[k].data = arr[k];
        swaps[k].numswaps = 0;
    }

    int temp;

    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (swaps[j].data < swaps[min_idx].data)
            {
                min_idx = j;
            }
        }

        // swap min element with 'first' element
        if (min_idx != i)
        {
            temp = swaps[min_idx].data;
            swaps[min_idx].data = swaps[i].data;
            swaps[i].data = temp;

            for (int l = 0; l < n; l++)
            {
                if (arr[l] == swaps[min_idx].data || arr[l] == swaps[i].data)
                    (swaps[l].numswaps)++;
            }
        }
    }

    return swaps;
}

void printSwaps(element *swaps, int n)
{
    int totalSwaps = 0;

    for (int i = 0; i < n; i++)
    {
        printf("%d: %d\n", swaps[i].data, swaps[i].numswaps);
        totalSwaps += swaps[i].numswaps;
    }
    printf("Total # of swaps: %d\n\n", totalSwaps / 2);
}

int main()
{
    int n = 9;

    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

    printf("array 1 bubble sort:\n");
    element *bubbleSort1 = bubbleSort(array1, n);
    printSwaps(bubbleSort1, n);

    printf("array 2 bubble sort:\n");
    element *bubbleSort2 = bubbleSort(array2, n);
    printSwaps(bubbleSort2, n);

    printf("array 1 selection sort:\n");
    element *selectionSort1 = selectionSort(array1, n);
    printSwaps(selectionSort1, n);

    printf("array 2 selection sort:\n");
    element *selectionSort2 = selectionSort(array2, n);
    printSwaps(selectionSort2, n);

    free(bubbleSort1);
    free(bubbleSort2);
    free(selectionSort1);
    free(selectionSort2);

    return 0;
}