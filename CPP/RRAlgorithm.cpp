#include <iostream>

using namespace std;
// Round Robin Algorithm 

struct process
{
    int burst, wait, comp, f;
} p[20] = {0, 0};

int main()
{
    int n, i, j, totalwait = 0, totalturn = 0, quantum, flag = 1,
                 time = 0;
    cout << "\nEnter The No Of Process : ";
    cin >> n;
    cout << "\nEnter The Quantum time(in ms) : ";
    cin >> quantum;
    cout << endl;
    for (i = 0; i < n; i++)
    {
        cout << "Enter The Burst Time (in ms) For Process #" << i + 1 << " : ";
        cin >> p[i].burst;
        p[i].f = 1;
    }
    cout << "\nOrder Of Execution\n";
    cout << "\nProcess \tStarting Ending Remaining";
    cout << "\n\t\tTime\t Time\t Time";
    while (flag == 1)
    {
        flag = 0;
        for (i = 0; i < n; i++)
        {
            if (p[i].f == 1)
            {
                flag = 1;
                j = quantum;
                if ((p[i].comp) > quantum)
                {
                    p[i].comp += quantum;
                }
                else
                {
                    p[i].wait = time - p[i].comp;
                    j = p[i].burst - p[i].comp;
                    p[i].comp = p[i].burst;
                    p[i].f = 0;
                }
                cout << "\nprocess #" << i + 1 << "\t" << time << "\t" << time + j << "\t" << p[i].comp;
                time += j;
            }
        }
    }
    cout << "\n\n------------------";
    cout << "\nProcess\t\t WaitingTime \tTurnAround Time ";
    for (i = 0; i < n; i++)
    {
        cout << "\nProcess #" << i + 1 << "\t\t" << p[i].wait << "\t\t" << p[i].wait + p[i].burst;
        totalwait = totalwait + p[i].wait;
        totalturn = totalturn + p[i].wait + p[i].burst;
    }
    cout << "\n\nAverage\n------------------";
    cout << "\nWaiting Time : " << totalwait / (float)n << " ms";
    cout << "\nTurnAround Time : " << totalturn / (float)n << " ms\n\n";
}
