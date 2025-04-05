#include <iostream>
#include <vector>
using namespace std;

class Stack {
private:
    vector<int> elements;

public:
    // Function to push an element into the stack
    void push(int element) {
        elements.push_back(element);
        cout << element << " pushed into stack" << endl;
    }

    // Function to pop an element from the stack
    void pop() {
        if (elements.empty()) {
            cout << "Stack underflow, cannot pop" << endl;
        } else {
            int poppedElement = elements.back();
            elements.pop_back();
            cout << poppedElement << " popped from stack" << endl;
        }
    }

    // Function to display the stack
    void display() {
        cout << "Stack: ";
        for (int i = elements.size() - 1; i >= 0; i--) {
            cout << elements[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.display();
    
    stack.pop();
    stack.display();
    
    stack.pop();
    stack.display();
    
    stack.pop();
    stack.display();
    
    stack.pop(); // Attempt to pop from an empty stack
    
    return 0;
}
