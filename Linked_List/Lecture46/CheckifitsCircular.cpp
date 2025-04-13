#include <iostream>
using namespace std;

// Definition of Node
struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Function to check if linked list is circular
bool isCircular(Node* head) {
    if (head == NULL) return true;

    Node* temp = head->next;

    while (temp != NULL && temp != head) {
        temp = temp->next;
    }

    return temp == head;
}

// Helper function to print the result
void checkCircular(Node* head) {
    if (isCircular(head))
        cout << "The linked list is circular." << endl;
    else
        cout << "The linked list is not circular." << endl;
}

int main() {
    // Create nodes
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);

    // Link nodes
    head->next = second;
    second->next = third;
    third->next = head;  // To make it circular

    // Check if circular
    checkCircular(head);

    // Create a non-circular list
    Node* head2 = new Node(10);
    head2->next = new Node(20);
    head2->next->next = new Node(30);

    // Check if circular
    checkCircular(head2);

    return 0;
}
