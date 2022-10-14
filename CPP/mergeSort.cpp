#include <iostream>
#include <chrono>
// #include "components/sorting.h"

using namespace std;
using namespace std::chrono;

int size;

void display(int arr[], int size)
{
    cout << "Values are: ";
    for (int i = 0; i < size; i++)
    {
        cout << "\t" << arr[i];
    }
    cout << endl;
}

void merge(int arr[], int beg, int mid, int end)
{
    int n1, n2; // creating two parts

    n1 = mid - beg + 1; // qty of first half of part
    n2 = end - mid;     // qty of second half of the part

    int L[n1], M[n2]; // creating two arrays of resp. qty

    int i, j, k;
    // inserting values from orignal array into two arrays
    for (i = 0; i < n1; i++)
    {
        L[i] = arr[beg + i];
    }

    for (j = 0; j < n2; j++)
    {
        M[j] = arr[mid + 1 + j];
    }

    i = 0, j = 0, k = beg;

    // While Both arrays have space
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

    // When either of Arrays don't have space

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

void sort(int arr[], int beg, int end)
{
    if (beg < end)
    {
        int mid = beg + (end - beg) / 2;
        sort(arr, beg, mid);
        sort(arr, mid + 1, end);

        merge(arr, beg, mid, end);
    }
}

int main()
{
    // int arr[] = {6, 5, 12, 10, 9, 1};
    // int size = sizeof(arr) / sizeof(arr[0]);
    cout << "Enter the Number of elements in the Array: ";
    cin >> size;

    int arr[size];
    cout << "\nEnter the Elements" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "\nDisplaying Unsorted Array ";
    display(arr, size);

    auto start = high_resolution_clock::now();

    sort(arr, 0, size - 1);
    cout << "\nDisplaying Sorted Array ";
    display(arr, size);

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);
    cout << duration.count() << endl;
    return 0;
}