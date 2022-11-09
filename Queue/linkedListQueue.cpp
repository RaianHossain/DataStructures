#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

bool IsEmpty()
{
    if(front == NULL && rear == NULL) return true;
    else return false;
}

void EnQueue(int x)
{
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;

    if(IsEmpty()) {
        front = rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }
}

void DeQueue()
{
    if(IsEmpty()) {
        cout<<"Queue is already empty!"<<endl;
        return;
    }
    Node* temp = front;
    if(front == rear) {
        front = rear = NULL;
    } 
    else {
        front = front->next;
    }
    free(temp);
}

void Print()
{
    if(IsEmpty()) {
        cout<<"Queue is empty!"<<endl;
        return;
    }
    Node* current = front;
    while(current != NULL) {
        cout<<current->data<<" ";
        current = current->next;
    }
    cout<<endl;
}

Node* Front()
{
    return front;
}

int main()
{
    EnQueue(1);
    EnQueue(2);
    EnQueue(3);
    DeQueue();
    // Print();
    cout<<Front()->data<<endl;
}