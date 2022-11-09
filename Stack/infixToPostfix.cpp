#include <iostream>
#include <stack>
#include <string>

using namespace std;

int operatorWeight(char op)
{
    int weight = -1;
    switch (op) {
        case '+':
        case '-':
            weight = 1;
            break;
        case '*':
        case '/':
            weight = 2;
            break;
        default:
            weight = 2;
            break;
    }
    return weight;
}

bool HigherPrec(char a, char b) 
{
    int aWeight = operatorWeight(a);
    int bWeight = operatorWeight(b);
    

    if(aWeight < bWeight) {
        return false;
    } else {
        return true;
    }
}

bool isOperator(char c)
{
    if(c == '+') return  true;
    else if(c == '-') return  true;
    else if(c == '/') return  true;
    else if(c == '*') return  true;
    else return false;

}

string postFixed(string expression) 
{
    stack<char>  S;
    string result;
    int size = expression.length();
    for (int i = 0; i < size; i++) {
        if(!isOperator(expression[i]) && expression[i] != '(' && expression[i] != ')') {
            result += expression[i];
        } 
        else if(isOperator(expression[i])) {
            while(!S.empty() && S.top() != '(' && HigherPrec(S.top(), expression[i])) {

                result += S.top();
                S.pop();
            }
            S.push(expression[i]);
        }
        else if (expression[i] == '(') {
            S.push(expression[i]);
        }
        else if (expression[i] == ')') {
            while(!S.empty() && S.top() != '(') {
                result += S.top();
                S.pop();
            }
            S.pop();
        }
    }
    while(!S.empty()) {
        result += S.top();
        S.pop();
    };

    return result;
}

int main()
{
    string expression;
    cout<<"Enter the expression: ";
    cin>>expression;
    string result = postFixed(expression);
    cout<<result<<endl;
    
    return 0;

}