// Write a program to convert an infix expression to postfix and prefix conversion
// Made by Yashika 2K21/EP/118
#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}
string infixToPostfix(const string &infix)
{
    stack<char> operators;
    string postfix;
    for (char c : infix)
    {
        if (isalnum(c))
        {
            postfix += c;
        }
        else if (c == '(')
        {
            operators.push(c);
        }
        else if (c == ')')
        {
            while (!operators.empty() && operators.top() != '(')
            {
                postfix += operators.top();
                operators.pop();
            }
            if (!operators.empty() && operators.top() == '(')
            {
                operators.pop();
            }
        }
        else if (isOperator(c))
        {
            while (!operators.empty() && precedence(c) <= precedence(operators.top()))
            {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }
    while (!operators.empty())
    {
        postfix += operators.top();
        operators.pop();
    }
    return postfix;
}
string infixToPrefix(const string &infix)
{
    string reversedInfix(infix.rbegin(), infix.rend());
    for (char &c : reversedInfix)
    {
        if (c == '(')
            c = ')';
        else if (c == ')')
            c = '(';
    }
    string reversedPostfix = infixToPostfix(reversedInfix);
    return string(reversedPostfix.rbegin(), reversedPostfix.rend());
}
int main()
{
    string infixExpression;
    cout << "Enter an infix expression: ";
    cin >> infixExpression;
    string postfixExpression = infixToPostfix(infixExpression);
    string prefixExpression = infixToPrefix(infixExpression);
    cout << "Postfix Expression: " << postfixExpression << endl;
    cout << "Prefix Expression: " << prefixExpression << endl;
    return 0;
}
