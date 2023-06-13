#include <bits/stdc++.h>

using namespace std;

char info[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',};
int leftChild[10] = {1, 3, 5, -1, -1, 8, -1, -1, -1, -1};
int rightChild[10] = {2, 4, 6, 7, -1, 9, -1, -1, -1, -1};
int root = 0;

void preOrder(){
    stack <int> tree;
    tree.push(-1);
    // tree.push (root);
    int pointer = root;
    while (pointer != -1) {
        cout<<info [pointer]<<endl;
        if(rightChild[pointer] != -1){
            tree.push(rightChild[pointer]);
        }
        if(leftChild[pointer] != -1){
            pointer = leftChild[pointer];
        }
        else {
            pointer = tree.top();
            tree.pop();
        }
    }
}


void inOrder()
{
    stack <int> tree;
    tree.push(-1);
    int pointer = root;
    while(pointer != -1) {
        tree.push(pointer);
        pointer = leftChild[pointer];
    }
    pointer = tree.top();
    tree.pop();
    while(pointer != -1) {
        cout<<info[pointer]<<endl;
        if(rightChild[pointer] != -1) {
            pointer = rightChild[pointer];
            while(pointer != -1) {
                tree.push(pointer);
                pointer = leftChild[pointer];
            }
        }
        pointer = tree.top();
        tree.pop();
    }

}

void postOrder() {
    vector <int> traversed;
    stack <int> stk;

    stk.push(root);
    while(!stk.empty()) {
        int current = stk.top();
        traversed.insert(traversed.begin(), current);
        stk.pop();
        if(leftChild[current] != -1) {
            stk.push(leftChild[current]);
        }
        if(rightChild[current] != -1) {
            stk.push(rightChild[current]);
        }
    }

    for(auto i = traversed.begin(); i != traversed.end(); i++) {
        cout<<info[*i]<<endl;
    }
}



int main(){
    postOrder();

    return 0;
}