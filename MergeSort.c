#include <stdio.h>

int size;


void display(int arr[], int size){
    printf("\nDisplaying Valuess: ");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int arr[], int beg, int mid, int end)
{
    int n1, n2;

    n1 = mid - beg + 1;
    n2 = end - mid;

    int L[n1], M[n2];

    int i, j, k;

    for (i = 0; i < n1; i++)
    {
        L[i] = arr[beg + i];
    }
    for (j = 0; j < n2; j++)
    {
        M[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = beg;

    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int beg, int end)
{
    if (beg < end)
    {
        int mid = (beg + end) / 2;
        mergeSort(arr, beg, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, beg, mid, end);
    }
}

void main()
{
    printf("\nEnter the Number of Elements: ");
    scanf("%d", &size);
    int arr[size];
    printf("\nEnter the Elements:\n");
    for (int i = 0; i <= size - 1; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\nUnsorted Array: ");
    display(arr, size);
    printf("\nSorted Array: ");
    mergeSort(arr, 0, size - 1);
    display(arr, size);
    printf("\n\n");
}