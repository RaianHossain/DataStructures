#include <iostream>
#include <queue>
#include<math.h>
using namespace std;


class Node {
public:
    int data;
    Node* left;
    Node* right;
};

Node* CreateNode(int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* Insert(Node* root, int data)
{
    if(root == NULL) {
        root = CreateNode(data);
    }
    else if(data <= root->data) {
        root->left = Insert(root->left, data);
    }
    else if(data > root->data) {
        root->right = Insert(root->right, data);
    }
    return root;
}

bool Search(Node* root, int data)
{
    if(root == NULL) return false;
    else if(root->data == data) return true;
    else if(data <= root->data) Search(root->left, data);
    else if(data > root->data) Search(root->right, data);
}

int FinMin(Node* root)
{
    if(root == NULL) {
        cout<<"Tree is empty!"<<endl;
        return -1;
    }
    while(root->left == NULL) {
        return root->data;
    }
    return FinMin(root->left);
}

int FindMax(Node* root)
{
    if(root == NULL) {
        cout<<"Tree is empty"<<endl;
        return 0;
    }
    if(root->right == NULL) {
        return root->data;
    }
    return FindMax(root->right);
}

int findHeight(Node* root) 
{
    if(root == NULL) return -1;
    return max(findHeight(root->left), findHeight(root->right)) + 1;
}

void levelOrderTraversal(Node* root) 
{
    if(root == NULL) return;
    queue <Node*> Q;
    Q.push(root);
    while(!Q.empty()) {
        Node* current = Q.front();
        cout<<current->data<<endl;
        if(current->right != NULL) Q.push(current->right);
        if(current->left != NULL) Q.push(current->left);
        Q.pop();
    }
}

void preorder(Node* root) 
{
    if(root == NULL) return;
    cout<<root->data<<endl;
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) 
{
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->data<<endl;
    inorder(root->right);
}
void postorder(Node* root) 
{
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<endl;
}

bool isSubtreeLesser(Node* root, int value)
{
    if(root == NULL) return true;
    if(root->data <= value && isSubtreeLesser(root->left, value) && isSubtreeLesser(root->right, value)) return true;
    else return false;
}

bool isSubtreeGreater(Node* root, int value)
{
    if(root == NULL) return true;
    if(root->data > value && isSubtreeGreater(root->left, value) && isSubtreeGreater(root->right, value)) return true;
    else return false;
}

bool isBinarySearchTree(Node* root) 
{
    if(root == NULL) return true;
    if(isSubtreeLesser(root->left, root->data) && isSubtreeGreater(root->right, root->data) && isBinarySearchTree(root->left) && isBinarySearchTree(root->right)) return true;
    else return false;
}

bool isBSTUtil(Node* root, int minValue, int maxValue) 
{
    if(root == NULL) return true;
    if(root->data > minValue && root->data < maxValue && isBSTUtil(root->left, minValue, root->data) && isBSTUtil(root->right, root->data, maxValue)) return true;
    else return false;
}

bool isBinarySearchTreeOptimized(Node* root)
{
    return isBSTUtil(root, INFINITY*-1, INFINITY);
}

int main()
{
    Node* root = NULL;
    // cout<<root<<endl;
    root = Insert(root, -15);
    // cout<<root<<endl;
    root = Insert(root, 25);
    root = Insert(root, 63);
    root = Insert(root, 75);
    root = Insert(root, 13);
    root = Insert(root, 11);
    root = Insert(root, 5);
    root = Insert(root, 3);
    
    cout<<isBinarySearchTree(root)<<endl;
    return 0;

}
