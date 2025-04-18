#include <iostream>
#include <stack>
using namespace std;

void insertatbottom(stack<int> &stack, int x) {
    if (stack.empty()) {
        stack.push(x);
        return;
    }

    int num = stack.top();
    stack.pop();

    insertatbottom(stack, x);

    stack.push(num);
}

void reverseStack(stack<int> &stack) {
    if (stack.empty()) {
        return;
    }

    int num = stack.top();
    stack.pop();

    reverseStack(stack);

    insertatbottom(stack, num);
}

int main() {
    stack<int> s;

    // Push elements into the stack
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout << "Original Stack (top to bottom): ";
    stack<int> temp = s;
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    reverseStack(s);

    cout << "Reversed Stack (top to bottom): ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}
