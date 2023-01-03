#include <iostream>

using namespace std;
// Shortest Job First Alogrithm 

struct process
{
    int burst, wait, no;
} p[20] = {0, 0};

int main()
{
    int n, i, j, totalwait = 0, totalturn = 0;
    cout << "\nEnter The No Of Process : ";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cout << "Enter The Burst Time (in ms) For Process #" << i + 1 << " : ";
        cin >> p[i].burst;
        p[i].no = i + 1;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (p[j].burst > p[j + 1].burst)
            {
                p[j].burst ^= p[j + 1].burst ^= p[j].burst ^= p[j + 1].burst;
                p[j].no ^= p[j + 1].no ^= p[j].no ^= p[j + 1].no;
            }
        }
    }
    cout << "\nProcess\t\t WaitingTime \tTurnAroundTime ";
    for (i = 0; i < n; i++)
    {
        cout << "\nProcess #" << p[i].no << "\t\t" << p[i].wait << "\t\t" << p[i].wait + p[i].burst;
        p[i + 1].wait = p[i].wait + p[i].burst;
        totalwait = totalwait + p[i].wait;
        totalturn = totalturn + p[i].wait + p[i].burst;
    }
    cout << "\n\nAverage\n---------";
    cout << "\nWaiting Time : " << totalwait / (float)n << " ms";
    cout << "\nTurnAround Time : " << totalturn / (float)n << " ms\n\n";
    return 0;
}
