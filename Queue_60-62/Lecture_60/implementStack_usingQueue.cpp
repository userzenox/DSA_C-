#include <iostream>
#include <queue>
using namespace std;

class MyStack {
    queue<int> q1, q2;

public:
    MyStack() {}

    void push(int x) {
        if (!q1.empty())
            q1.push(x);
        else
            q2.push(x);
    }

    int pop() {
        if (empty()) return -1;

        if (!q1.empty()) {
            while (q1.size() > 1) {
                q2.push(q1.front());
                q1.pop();
            }
            int ans = q1.front();
            q1.pop();
            return ans;
        } else {
            while (q2.size() > 1) {
                q1.push(q2.front());
                q2.pop();
            }
            int ans = q2.front();
            q2.pop();
            return ans;
        }
    }

    int top() {
        if (empty()) return -1;

        int ans;
        if (!q1.empty()) {
            while (!q1.empty()) {
                ans = q1.front();
                q2.push(ans);
                q1.pop();
            }
        } else {
            while (!q2.empty()) {
                ans = q2.front();
                q1.push(ans);
                q2.pop();
            }
        }
        return ans;
    }

    bool empty() {
        return q1.empty() && q2.empty();
    }
};

int main() {
    MyStack* stack = new MyStack();

    stack->push(10);
    stack->push(20);
    stack->push(30);

    cout << "Top element: " << stack->top() << endl;        // Should print 30
    cout << "Popped: " << stack->pop() << endl;             // Should print 30
    cout << "Top element after pop: " << stack->top() << endl; // Should print 20
    cout << "Popped: " << stack->pop() << endl;             // Should print 20
    cout << "Popped: " << stack->pop() << endl;             // Should print 10

    cout << "Is stack empty? " << (stack->empty() ? "Yes" : "No") << endl; // Should print Yes

    delete stack;
    return 0;
}
