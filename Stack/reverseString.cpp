#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

void Reverse(char C[], int size)
{
    stack<char> S;
    for (int i = 0; i < size; i++) {
        S.push(C[i]);
    }

    for (int i = 0; i < size; i++) {
        C[i] = S.top();
        S.pop();
    }

    cout<<C<<endl;
}

int main()
{
    char C[51];
    cout<<"Enter the string: ";
    cin>>C;
    // cout<<strlen(C)<<endl;
    Reverse(C, strlen(C));

}