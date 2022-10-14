#include <iostream>
//? BE20F05F063 Jayesh Singh
using namespace std;

int main()
{
    int bno, pno, bsize[20], psize[20], fragment[20];

    int i, j;
    int alloc[20], occupied[20];

    cout << "\nEnter Number of Block: ";
    cin >> bno;
    cout << "Enter Number of Processes: ";
    cin >> pno;

    cout << endl;
    cout << "Enter Sizes of Blocks" << endl;
    for (i = 0; i < bno; i++)
    {
        cout << "Size of Block No " << i + 1 << " : ";
        cin >> bsize[i];
    }
    cout << endl;
    cout << "Enter Sizes of Blocks" << endl;
    for (i = 0; i < pno; i++)
    {
        cout << "Size of Process No " << i + 1 << " : ";
        cin >> psize[i];
    }

    for (i = 0; i < pno; i++)
    {
        alloc[i] = -1;
    }
    for (i = 0; i < bno; i++)
    {
        occupied[i] = 0;
    }

    for (int i = 0; i < pno; i++)
    {
        int indexPlaced = -1;
        for (int j = 0; j < bno; j++)
        {
            if (bsize[j] >= psize[i] && !occupied[j])
            {
                if (indexPlaced == -1)
                {
                    indexPlaced = j;
                }
                else if (bsize[indexPlaced] < bsize[j])
                {
                    indexPlaced = j;
                }
            }
        }
        if (indexPlaced != -1)
        {
            alloc[i] = indexPlaced;
            occupied[indexPlaced] = 1;
            bsize[indexPlaced] -= psize[i];
        }
    }

    cout << "\n\nProcess No.\tProcessSize\tBlock No." << endl;
    for (i = 0; i < pno; i++)
    {
        cout << i + 1 << "\t\t" << psize[i] << "\t\t";
        if (alloc[i] != -1)
        {
            cout << alloc[i] + 1 << endl;
        }
        else
        {
            cout << "Not Allocated" << endl;
        }
    }

    cout << "\n"
         << endl;

    return 0;
}
