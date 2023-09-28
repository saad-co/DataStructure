#include <iostream>
#include "Stack.cpp"
#include <algorithm>

using namespace std;

bool isOperator(char c) {
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

string infixToPrefix(Stack<char> stk, string infix) {
    string prefix;
    reverse(infix.begin(), infix.end());
    for (int i = 0; i < infix.length(); i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        }
        else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }

    for (int i = 0; i < infix.length(); i++) {
        if (isalnum(infix[i])) {
            prefix += infix[i];
        }
        else if (infix[i] == '(') {
            stk.push(infix[i]);
        }
        else if (infix[i] == ')') {
            while (stk.top() != '(' && (!stk.isEmpty())) {
                prefix += stk.top();
                stk.pop();
            }
            if (stk.top() == '(') {
                stk.pop();
            }
        }
        else if (isOperator(infix[i])) {
            if (stk.isEmpty()) {
                stk.push(infix[i]);
            }
            else {
                if (priorityOrder(infix[i]) > priorityOrder(stk.top())) {
                    stk.push(infix[i]);
                }
                else if (priorityOrder(infix[i]) == priorityOrder(stk.top()) && infix[i] == '^') {
                    while (priorityOrder(infix[i]) == priorityOrder(stk.top())) {
                        prefix += stk.top();
                        stk.pop();
                    }
                    stk.push(infix[i]);
                }
                else if (priorityOrder(infix[i]) == priorityOrder(stk.top())) {
                    stk.push(infix[i]);
                }
                else {
                    while ((!stk.isEmpty()) && priorityOrder(infix[i]) < priorityOrder(stk.top())) {
                        prefix += stk.top();
                        stk.pop();
                    }
                    stk.push(infix[i]);
                }
            }
        }
    }
    while (!stk.isEmpty()) {
        prefix += stk.top();
        stk.pop();
    }
    reverse(prefix.begin(), prefix.end());
    return prefix;
}

int main() {
    string infix, prefix;
    cout << "Enter an INFIX expression: ";
    cin >> infix;
    Stack<char> st;
    prefix = infixToPrefix(st, infix);
    cout << "INFIX expression: " << infix << endl;
    cout << "PREFIX expression: " << prefix << endl;
    return 0;
}
