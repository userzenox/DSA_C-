#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Function to remove duplicates from sorted linked list
Node* removeDuplicates(Node *head) {
    if (head == NULL) {
        return NULL;
    }

    Node* temp = head;
    while (temp != NULL && temp->next != NULL) {
        if (temp->data != temp->next->data) {
            temp = temp->next;
        } else {
            Node* nodeDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeDelete;
        }
    }
    return head;
}

// Helper function to print linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to append a node to the end
void append(Node*& head, int data) {
    if (head == NULL) {
        head = new Node(data);
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new Node(data);
}

// Main function
int main() {
    Node* head = NULL;

    // Sample sorted input: 1 -> 1 -> 2 -> 3 -> 3 -> 4
    append(head, 1);
    append(head, 1);
    append(head, 2);
    append(head, 3);
    append(head, 3);
    append(head, 4);

    cout << "Original List: ";
    printList(head);

    head = removeDuplicates(head);

    cout << "After Removing Duplicates: ";
    printList(head);

    return 0;
}
