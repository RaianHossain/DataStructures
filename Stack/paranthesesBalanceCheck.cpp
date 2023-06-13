#include<iostream>
#include<string>
#define MAX_SIZE 101 
using namespace std;

class Stack
{
private:
    char A[MAX_SIZE];  // array to store the stack
	int top;   // variable to mark the top index of stack. 
public:
	// constructor
	Stack()
	{
		top = -1; // for empty array, set top = -1
	}

	// Push operation to insert an element on top of stack. 
	void Push(char x) 
	{
	  if(top == MAX_SIZE -1) { // overflow case. 
			printf("Error: stack overflow\n");
			return;
		}
		A[++top] = x;
	}
 
	// Pop operation to remove an element from top of stack.
	void Pop() 
	{
		if(top == -1) { // If stack is empty, pop should throw error. 
			printf("Error: No element to pop\n");
			return;
		}
		top--;
	}
 
	// Top operation to return element at top of stack. 
	char Top() 
	{
		return A[top];
	}
 
	// This function will true if stack is empty, false otherwise.
	int IsEmpty()
	{
		if(top == -1) return 1;
		return 0;
	}

	// This will print all the elements in the stack at any stage. 
	void Print() {
		int i;
		printf("Stack: ");
		for(i = 0;i<=top;i++)
			printf("%d ",A[i]);
		printf("\n");
	}
};
// Function to check whether two characters are opening 
// and closing of same type. 
bool ArePair(char opening,char closing)
{
	if(opening == '(' && closing == ')') return true;
	else if(opening == '{' && closing == '}') return true;
	else if(opening == '[' && closing == ']') return true;
	return false;
}
bool AreParanthesesBalanced(string exp)
{
	Stack S;
	for(int i =0;i<exp.length();i++)
	{
		if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
			S.Push(exp[i]);
		else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
		{
			if(S.IsEmpty() || !ArePair(S.Top(),exp[i]))
				return false;
			else
				S.Pop();
		}
	}
	return S.IsEmpty() ? true:false;
}

int main()
{
	/*Code to test the function AreParanthesesBalanced*/
	string expression;
	cout<<"Enter an expression:  ";
	cin>>expression;
	if(AreParanthesesBalanced(expression))
		cout<<"Balanced\n";
	else
		cout<<"Not Balanced\n";
	cout<<endl;
}