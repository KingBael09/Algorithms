#include <iostream>

using namespace std;

int mutex = 1;
int full = 0;
int empty = 5, x = 0;

void Producer()
{
    --mutex;
    ++full;
    --empty;
    x++;
    cout << "\nProducer produce item: " << x;
    ++mutex;
}
void Consumer()
{
    --mutex;
    --full;
    ++empty;
    cout << "\nConsumer consumes item: " << x;
    x--;
    ++mutex;
}
int main()
{
    int choice, i;
    cout << "\n1.Producer\n2.Consumer\n3.Exit";
    for (i = 1; i > 0; i++)
    {
        cout << "\nEnter your Choice Code: ";
        cin >> choice;
        switch (choice)
        {
        case 1:

            if ((mutex == 1) &&
                (empty != 0))
            {
                Producer();
            }
            else
            {
                cout << "\nBuffer is full....!";
            }
            break;
        case 2:
            if ((mutex == 1) &&
                (full != 0))
            {
                Consumer();
            }
            else
            {
                cout << "\nBuffer is empty....!";
            }
            break;
        case 3:
            exit(0);
            break;
        default:
            cout << "Please Enter The Correct Choice Code......!";
        }
    }
    return 0;
}
