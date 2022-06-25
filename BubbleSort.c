#include <stdio.h>

int i, j;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubble(int a[], int n)
{
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[i])
            {
                swap(&a[i], &a[j]);
            }
        }
    }
}

void display(int a[], int n)
{

    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

void main()
{
    int size;

    printf("\nEnter Array Length: ");
    scanf("%d", &size);

    int arr[size];

    printf("\nEnter Unsorted Array:\n");
    for (i = 0; i <= size - 1; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\n\nBefore Sorting: ");
    display(arr, size);
    printf("\n\nAfter Sorting: ");
    bubble(arr, size);
    display(arr, size);
    printf("\n\n");
}