#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

Node* top = NULL;

void Push(int x) 
{
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

void Pop() 
{
    Node* temp = new Node();
    if(top == NULL){
        cout<<"Stack is empty"<<endl;
        return;
    }
    temp = top;
    top = top->next;
    free(temp);
}

void Print()
{
    Node* temp = top;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* Top()
{
    return top;
}

bool isEmpty()
{
    if(top == NULL) return true;
    return false;
}

int main()
{
    Push(3);
    Push(2);
    Push(1);
    Pop();
    Print();
    Node* temp = Top();
    cout<<temp->data<<endl;
    return 0;


}