#include <iostream>
using namespace std;

// Node structure for Doubly Linked List
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

// Doubly Linked List class
class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() {
        head = nullptr;
    }

    // Function to add a node at the beginning of the list
    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
    }

    // Function to reverse the doubly linked list
    void reverse() {
        Node* temp = nullptr;
        Node* current = head;

        // Traverse and swap next and prev for each node
        while (current != nullptr) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;  // Move to the next node (which was previous)
        }

        // Update head to point to the new front node
        if (temp != nullptr) {
            head = temp->prev;
        }
    }

    // Function to print the list
    void printList() {
        Node* node = head;
        while (node != nullptr) {
            cout << node->data;
            if (node->next != nullptr) cout << " <-> ";
            node = node->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    
    dll.push(10);
    dll.push(20);
    dll.push(30);
    dll.push(40);

    cout << "Original Doubly Linked List:" << endl;
    dll.printList();

    dll.reverse();

    cout << "Reversed Doubly Linked List:" << endl;
    dll.printList();

    return 0;
}
