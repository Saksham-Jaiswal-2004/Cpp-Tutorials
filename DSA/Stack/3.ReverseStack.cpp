#include<iostream>
#include<stack>

using namespace std;

void insertAtBottom(stack<int> &stack, int element) {
    if (stack.empty()) {
        stack.push(element);
        return;
    }

    int topElement = stack.top();
    stack.pop();
    insertAtBottom(stack, element);
    stack.push(topElement);
}

void reverseStack(stack<int> &stack) {
    if (stack.empty()) return;

    int topElement = stack.top();
    stack.pop();
    reverseStack(stack);
    insertAtBottom(stack, topElement);
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(4);
    s.push(0);
    s.push(8);
    s.push(2);
    s.push(0);
    s.push(0);
    s.push(5);

    reverseStack(s);

    return 0;
}