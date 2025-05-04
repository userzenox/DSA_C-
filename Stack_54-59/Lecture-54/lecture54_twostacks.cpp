#include <iostream>
using namespace std;

class TwoStack {
public:
    int *arr;
    int top1;
    int top2;
    int size;

    // Constructor
    TwoStack(int s) {
        this->size = s;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    // Push in stack 1.
    void push1(int num) {
        if (top1 < top2 - 1) {
            arr[++top1] = num;
        } else {
            cout << "Stack Overflow in Stack 1\n";
        }
    }

    // Push in stack 2.
    void push2(int num) {
        if (top1 < top2 - 1) {
            arr[--top2] = num;
        } else {
            cout << "Stack Overflow in Stack 2\n";
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        if (top1 >= 0) {
            return arr[top1--];
        } else {
            return -1;  // Stack 1 is empty
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        if (top2 < size) {
            return arr[top2++];
        } else {
            return -1;  // Stack 2 is empty
        }
    }

    // Destructor to free allocated memory
    ~TwoStack() {
        delete[] arr;
    }
};

int main() {
    TwoStack ts(5);  // Create a TwoStack with total size 5

    // Pushing into stack 1
    ts.push1(10);
    ts.push1(20);

    // Pushing into stack 2
    ts.push2(30);
    ts.push2(40);

    // Trying to push into full array
    ts.push1(50);    // Should succeed
    ts.push2(60);    // Should show overflow

    // Popping from stack 1
    cout << "Pop from stack 1: " << ts.pop1() << endl; // 50
    cout << "Pop from stack 1: " << ts.pop1() << endl; // 20
    cout << "Pop from stack 1: " << ts.pop1() << endl; // 10
    cout << "Pop from stack 1: " << ts.pop1() << endl; // -1

    // Popping from stack 2
    cout << "Pop from stack 2: " << ts.pop2() << endl; // 40
    cout << "Pop from stack 2: " << ts.pop2() << endl; // 30
    cout << "Pop from stack 2: " << ts.pop2() << endl; // -1

    return 0;
}
