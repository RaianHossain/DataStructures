#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
};

class LinkedList {
    private:
    Node* head;
    Node* tail;

    public:
    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    void insertBegining(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        if(head == NULL) tail = newNode;
        head = newNode;
        return;
    }

    void insertEnd(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;
        if(head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
        return;
    }

    void print() {
        Node* temp = new Node();
        temp = head;
        if(head == NULL) {
            cout<<"Linked list is empty"<<endl;
            return;
        }
        while(temp != NULL) {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
        return;
    }

    int size() {
        int counter = 0;
        Node* temp = new Node();
        temp = head;
        while(temp != NULL) {
            temp = temp->next;
            counter++;
        }
        return counter;
    }

    void deleteNode(int pos) {
        if(pos > size()) {
            cout<<"Invalid position "<<endl;
            return;
        }
        Node* temp = head;
        if(pos == 0) {
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
};

int main()
{
    LinkedList lst;
    lst.insertBegining(2);
    lst.insertEnd(3);
    lst.insertBegining(1);
    lst.insertEnd(4);
    lst.print();
    lst.deleteNode(5);
    lst.deleteNode(4);
    lst.print();

    return 0;
}
