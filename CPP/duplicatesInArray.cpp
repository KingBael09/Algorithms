#include <iostream>

using namespace std;

int status = 0;

void isDuplicate(int nums[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (nums[i] == nums[j])
            {
                status = 1;
                break;
            }
        }
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};

    int arrSize = sizeof(arr) / sizeof(arr[0]);

    isDuplicate(arr, arrSize);

    if (status == 1)
    {
        cout << "\nContains Duplicate" << endl;
    }
    else
    {
        cout << "\nDosen't Contain Duplicate" << endl;
    }
}
