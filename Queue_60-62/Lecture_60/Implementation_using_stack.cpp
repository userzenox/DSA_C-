#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
    stack<int> input, output;

public:
    MyQueue() {}

    // Push element x to the back of queue
    void push(int x) {
        input.push(x);
    }

    // Removes the element from in front of queue and returns that element
    int pop() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        int ans = output.top();
        output.pop();
        return ans;
    }

    // Get the front element
    int peek() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }

    // Returns whether the queue is empty
    bool empty() {
        return input.empty() && output.empty();
    }
};

// Test the MyQueue class
int main() {
    MyQueue* obj = new MyQueue();

    cout << "Enqueue 10, 20, 30\n";
    obj->push(10);
    obj->push(20);
    obj->push(30);

    cout << "Front element: " << obj->peek() << endl; // Expected: 10
    cout << "Removed element: " << obj->pop() << endl; // Expected: 10
    cout << "Front element after pop: " << obj->peek() << endl; // Expected: 20

    cout << "Is queue empty? " << (obj->empty() ? "Yes" : "No") << endl; // Expected: No

    obj->pop(); // Removes 20
    obj->pop(); // Removes 30

    cout << "Is queue empty after all pops? " << (obj->empty() ? "Yes" : "No") << endl; // Expected: Yes

    delete obj;
    return 0;
}
