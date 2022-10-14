#include <iostream>
//? BE20F05F063 Jayesh Singh
using namespace std;

int main()
{
    int bsize[10], psize[10], bno, pno, flags[10], alloc[10];
    int i, j;
    for (i = 0; i < 10; i++)
    {
        flags[i] = 0;
        alloc[i] = -1;
    }
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
        for (j = 0; j < bno; j++)
        {
            if (flags[j] == 0 && bsize[j] >= psize[i])
            {
                alloc[j] = i;
                flags[j] = 1;
                break;
            }
        }
    }
    cout << "\n\nBlock No.\tBlockSize\tProcess No.\tProcessSize";
    for (i = 0; i < bno; i++)
    {
        cout << "\n"
             << i + 1 << "\t\t" << bsize[i] << "\t\t";

        if (flags[i] == 1)
        {
            cout << alloc[i] + 1 << "\t\t" << psize[alloc[i]];
        }
        else
        {
            cout << "-"
                 << "\t\tNot Allocated";
        }
    }
    cout << "\n"
         << endl;
    return 0;
}
