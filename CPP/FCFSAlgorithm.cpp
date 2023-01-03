#include <iostream>

using namespace std;
// First Come First Serve Alogrithm

struct process
{
    int burst, wait;
} p[20] = {0, 0};

int main()
{
    int n, i, totalwait = 0, totalturn = 0;
    cout << "\nEnter The No Of Process : ";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cout << "Enter The Burst Time (in ms) For Process #" << i + 1 << " : ";
        cin >> p[i].burst;
    }
    cout << "\nProcess\t Waiting Time \tTurnAround Time ";
    cout << "\n\t (in ms)\t (in ms)";
    for (i = 0; i < n; i++)
    {
        cout << "\nProcess #" << i + 1 << "\t" << p[i].wait << "\t" << p[i].wait + p[i].burst;
        p[i + 1].wait = p[i].wait + p[i].burst;
        totalwait = totalwait + p[i].wait;
        totalturn = totalturn + p[i].wait + p[i].burst;
    }
    cout << "\n\nAVERAGE\n---------";
    cout << "\nWaiting Time : " << totalwait / (float)n << " ms";
    cout << "\nTurnAround Time : " << totalturn / (float)n << " ms\n\n";
    return 0;
}
