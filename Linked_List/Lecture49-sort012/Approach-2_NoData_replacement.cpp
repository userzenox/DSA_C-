#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        this->data = d;
        this->next = NULL;
    }
};

// Insert at tail
void insertAtTail(Node* &tail, Node* curr) {
    tail->next = curr;
    tail = curr;
}

// Your sortList function
Node* sortList(Node *head) {
    Node* Zerohead = new Node(-1);
    Node* Zerotail = Zerohead;
    Node* Onehead = new Node(-1);
    Node* Onetail = Onehead;
    Node* Twohead = new Node(-1);
    Node* Twotail = Twohead;

    Node* curr = head;
    while (curr != NULL) {
        int value = curr->data;

        if (value == 0) {
            insertAtTail(Zerotail, curr);
        } else if (value == 1) {
            insertAtTail(Onetail, curr);
        } else {
            insertAtTail(Twotail, curr);
        }

        curr = curr->next;
    }

    if (Onehead->next != NULL) {
        Zerotail->next = Onehead->next;
    } else {
        Zerotail->next = Twohead->next;
    }

    Onetail->next = Twohead->next;
    Twotail->next = NULL;

    head = Zerohead->next;

    delete Zerohead;
    delete Onehead;
    delete Twohead;

    return head;
}

// Function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to insert a new node at the end
void append(Node* &head, int data) {
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

int main() {
    Node* head = NULL;

    // Sample input: 1 -> 2 -> 0 -> 1 -> 2 -> 0 -> 1
    append(head, 1);
    append(head, 2);
    append(head, 0);
    append(head, 1);
    append(head, 2);
    append(head, 0);
    append(head, 1);

    cout << "Original List: ";
    printList(head);

    head = sortList(head);

    cout << "Sorted List: ";
    printList(head);

    return 0;
}
