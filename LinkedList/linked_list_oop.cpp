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
            cout<<"The list is empty"<<endl;
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
    void deleteFromBeginning() {
        if(head == NULL) {
            cout<<"The list is empty"<<endl;
            return;
        }
        Node* temp = head;
        head = temp->next;
        free(temp);
        return;
    }

    void deleteFromEnd() {
        if(head == NULL) {
            cout<<"The list is empty"<<endl;
            return;
        }
        if(head == tail) {
            free(head);
            head = tail = NULL;
            return;
        }
        Node* temp = head;
        Node* secondLast = NULL;
        while(temp != NULL) {
            if(temp->next != NULL) secondLast = temp;          
            temp = temp->next;
        }
        free(secondLast->next);
        secondLast->next = NULL;
        tail = secondLast;
        return;
    }

    int search(int n) {
        if(head == NULL) {
            return -1;
        }
        Node* temp = head;
        int counter = 0;
        while(temp != NULL) {
            if(temp->data == n) {
                return counter;
            }
            temp = temp->next;
            counter++;
        }
        return -1;
    }
};

int main()
{
    LinkedList lst;
    lst.insertBegining(2);
    lst.insertEnd(3);
    lst.insertBegining(1);
    lst.insertEnd(4);
    cout<<"After inserting: ";
    lst.print();
    int pos = lst.search(4);
    cout<<"Searching 4: ";
    cout<<"Found at "<<pos<<endl;
    lst.deleteFromBeginning();
    cout<<"After deleting from beginning: ";
    lst.print();
    lst.deleteFromEnd();
    cout<<"After deleting from end: ";
    lst.print();
    cout<<endl;

    return 0;
}
