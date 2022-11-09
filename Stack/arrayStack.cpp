#include <iostream>
using namespace std;
#define MAX_SIZE 101

int A[MAX_SIZE];
int top = -1;

void Push(int x)
{
    if(top == (MAX_SIZE - 1)) {
        cout<<"Array overflowed"<<endl;
        return;
    }
    top++;
    A[top] = x;
}

bool isEmpty()
{
    if(top == -1) {
        return true;
    } else {
        return false;
    }
}

void Pop()
{
    if(isEmpty() == true) {
        cout<<"Stack is already empty"<<endl;
        return;
    }
    top--;
}

int Top()
{
    return A[top];
}

void Print() 
{
    for(int i=0; i<=top; i++) {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    Push(1);
    Push(2);
    Print();
    return 0;
}


