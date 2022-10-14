#include <iostream>
#define maxSize 10

using namespace std;

class queue
{
    int queueArray[maxSize], front, rear;

public:
    queue()
    {
        front = -1;
        rear = -1;
    }
    bool isFull()
    {
        if (front == 0 && rear == maxSize - 1)
        {
            return true;
        }
        return false;
    }
    bool isEmpty()
    {
        if (front == -1)
        {
            return true;
        }
        return false;
    }

    void enQueue(int value)
    {
        if (isFull())
        {
            cout << "Queue is Full" << endl;
        }
        else
        {
            if (isEmpty())
            {
                front = 0;
            }
            rear++;
            queueArray[rear] = value;
        }
    }

    void deQueue()
    {
        int value;
        if (isEmpty())
        {
            cout << "Queue is Empty!" << endl;
        }
        else
        {
            value = queueArray[front];
            if (front >= rear)
            {
                front = -1;
                rear = -1;
            }
            else
            {
                front++;
            }
            cout << "\nDeleted => " << value << " from Queue" << endl;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "\nQueue is Empty!" << endl;
        }
        else
        {
            for (int i = front; i <= rear; i++)
            {
                cout << queueArray[i] << "\t";
            }
        }
    }
};

int main()
{
    int choice;
    queue start;
    while (choice != 0)
    {
        cout << "\n\n\n1. Insert\n2. Delete\n3. Display\n"
             << endl;
        cout << "Enter your Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int val;
            cout << "\n\nEnter Value: ";
            cin >> val;
            start.enQueue(val);
            break;
        case 2:
            start.deQueue();
            break;
        case 3:
            start.display();
            break;
        case 0:
            cout << "Thank You!" << endl;
            exit(0);
        default:
            cout << "\n\nInvalid Input!" << endl;
            break;
        }
    }
}
