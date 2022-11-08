#include <iostream>
using namespace std;

//Structure of a Node.
class Node {
    public:
    int data;
    Node* next;
};

//Declaring a global variable containing the head. Which can be accessed by anywhere.
Node* head = new Node();

//Function that insert always in the front.
void InsertInFront(int x) 
{
    // cout<<head<<endl;
    Node *temp = new Node();
    temp->data = x;
    temp->next = head;
    head = temp;
}

//Function that insert always in the end.
void InsertInEnd(int data) 
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    if(head == NULL) {
        newNode->next = head;
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

//Function that insert in a given position.
void InsertInNthPos(int data, int pos)
{
    Node* newNode = new Node();
    newNode->data = data;

    if(pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    for (int i = 0; i < pos - 2; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

//Function that delete a node of a certain position.
void Delete(int pos)
{
    Node* temp = head;
    if(pos == 1) {
        head = temp->next;
        free(temp);
        return;
    }
    for (int i=0; i<pos-2; i++) {
        temp = temp->next;
    }
    Node* nThNode = temp->next;
    temp->next = nThNode->next;
    free(nThNode);
}

//Function that reverse the linked list.
void Reverse() 
{
    Node* current = new Node();
    Node* prev = new Node();
    Node* next = new Node();
    current = head;
    prev = NULL;
    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

//Print Function.
void Print()
{
    Node* temp = head;
    cout<<"List is: ";
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()  
{
    // Node* head = new Node();
    head = NULL;
    /*
    cout<<head<<endl;
    Node* second = new Node();
    Node* third = new Node();

    head->data = 1;
    second->data = 2;
    third->data = 3;

    head->next = second;
    second->next = third;
    third->next = NULL;
    Print(head);

    InsertInFront(3);
    InsertInFront(2);
    InsertInFront(1);
    InsertInNthPos(0, 2);
    */
    InsertInEnd(7);
    InsertInEnd(8);
    InsertInFront(1);
    Delete(2);
    Reverse();
    Print();
}

//Note handleing edge cases like if the linked list is empty or given position does not exist etc.
//So be careful while inserting or deleting. Make sure of using correct indexes.