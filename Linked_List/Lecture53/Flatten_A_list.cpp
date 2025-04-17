#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* child;

    Node(int val) {
        data = val;
        next = nullptr;
        child = nullptr;
    }
};

// Merge two sorted child lists
Node* merge(Node* down, Node* right) {
    Node* dummy = new Node(-1);
    Node* temp = dummy;

    while (down != NULL && right != NULL) {
        if (right->data < down->data) {
            temp->child = right;
            right = right->child;
        } else {
            temp->child = down;
            down = down->child;
        }
        temp = temp->child;
    }

    while (right != NULL) {
        temp->child = right;
        right = right->child;
        temp = temp->child;
    }

    while (down != NULL) {
        temp->child = down;
        down = down->child;
        temp = temp->child;
    }

    Node* result = dummy->child;
    delete dummy;
    return result;
}

// Flatten the multi-level linked list
Node* flattenLinkedList(Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    Node* right = flattenLinkedList(head->next);
    head->next = NULL;

    return merge(head, right);
}

// Print flattened list
void printList(Node* head) {
    while (head) {
        cout << head->data << " → ";
        head = head->child;
    }
    cout << "null\n";
}

int main() {
    // Creating the multilevel linked list

    Node* head = new Node(5);
    head->next = new Node(10);
    head->next->next = new Node(19);
    head->next->next->next = new Node(28);

    head->child = new Node(7);
    head->child->child = new Node(8);
    head->child->child->child = new Node(30);

    head->next->child = new Node(20);

    head->next->next->child = new Node(22);
    head->next->next->child->child = new Node(50);

    head->next->next->next->child = new Node(35);
    head->next->next->next->child->child = new Node(40);
    head->next->next->next->child->child->child = new Node(45);

    // Flattening the list
    Node* flattened = flattenLinkedList(head);

    // Printing the result
    cout << "Flattened linked list:\n";
    printList(flattened);

    return 0;
}
