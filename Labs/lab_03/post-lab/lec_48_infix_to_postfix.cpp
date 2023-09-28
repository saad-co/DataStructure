#include <iostream>
#include "Stack.cpp"

using namespace std;

bool checkOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int priorityOrder(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string simpleConversion(Stack<char> stack, string infixExpression) {
    string postfixExpression;
    
    for (int i = 0; i < infixExpression.length(); i++) {
        char currentChar = infixExpression[i];
        
        if (isalnum(currentChar)) {
            postfixExpression += currentChar;
        }
        else if (checkOperator(currentChar)) {
            if (stack.isEmpty() || priorityOrder(currentChar) > priorityOrder(stack.top())) {
                stack.push(currentChar);
            }
            else if (priorityOrder(currentChar) == priorityOrder(stack.top()) && currentChar == '^') {
                stack.push(currentChar);
            }
            else {
                while (!stack.isEmpty() && priorityOrder(currentChar) <= priorityOrder(stack.top())) {
                    char temp = stack.top();
                    postfixExpression += temp;
                    stack.pop();
                }
                stack.push(currentChar);
            }
        }
        else if (currentChar == '(') {
            stack.push(currentChar);
        }
        else if (currentChar == ')') {
            while (!stack.isEmpty() && stack.top() != '(') {
                char temp = stack.top();
                postfixExpression += temp;
                stack.pop();
            }
            if (!stack.isEmpty() && stack.top() == '(') {
                stack.pop();
            }
        }
    }
    
    while (!stack.isEmpty()) {
        postfixExpression += stack.top();
        stack.pop();
    }
    
    return postfixExpression;
}

int main() {
    string infixExpression, postfixExpression;
    
    cout << "Enter an INFIX expression: ";
    cin >> infixExpression;
    
    Stack<char> stack;
    postfixExpression = simpleConversion(stack, infixExpression);
    
    cout << "INFIX expression: " << infixExpression << endl;
    cout << "POSTFIX expression: " << postfixExpression << endl;

    return 0;
}
