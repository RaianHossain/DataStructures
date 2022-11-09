#include <iostream>
#define MAX_SIZE 101
using namespace std;


class Queue {
private:
    int rear;
    int front;
public:
    int A[MAX_SIZE];
    Queue()
    {
        rear = -1;
        front = -1;
    }

    bool IsEmpty()
    {
        if(front == -1 && rear == -1) return true;
        else return false;
    }

    bool IsFull()
    {
        if(rear == (MAX_SIZE - 1)) return true;
        //if((rear+1)%MAX_SIZE == front) return true; //For circular array.
        else return false;
    }

    void EnQueue(int x)
    {
        if(IsFull()) {
            cout<<"Queue is full"<<endl;
            return;
        }
        else if(IsEmpty()) {
            front = rear = 0;
            A[rear] = x;
        }
        else {
            //rear = (rear + 1) % MAX_SIZE; //For curcular array.
            A[++rear] = x;
        }
    }

    void DeQueue() 
    {
        if(IsEmpty()) {
            cout<<"Queue is already empty!"<<endl;
        }
        else if(front == rear) {
            front = rear = -1;
        }
        else {
            front = front + 1;
            // front = (front + 1) % MAX_SIZE; //For cicular arrya.
        }
    }

    int Front() 
    {
        return A[front];
    }

    void Print()
    {
        for (int i = rear; i >= front; i--) {
            cout<<A[i]<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    Queue Q;
    Q.EnQueue(2);
    Q.EnQueue(1);
    Q.EnQueue(5);
    Q.DeQueue();
    int Front = Q.Front();
    cout<<Front<<endl;
    Q.Print();
}