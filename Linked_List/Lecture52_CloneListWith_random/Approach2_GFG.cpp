#include <iostream>
#include <unordered_map>
using namespace std;

// Node definition
struct Node {
    int data;
    Node* next;
    Node* random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};

// Solution class
class Solution {
public:
    Node* clone(Node* head) {
        if (head == NULL) return NULL;

        Node* temp = head;
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;

        while (temp != NULL) {
            Node* newNode = new Node(temp->data);
            if (cloneHead == NULL) {
                cloneHead = newNode;
                cloneTail = newNode;
            } else {
                cloneTail->next = newNode;
                cloneTail = newNode;
            }
            temp = temp->next;
        }

        return cloneHead;
    }

    Node* cloneLinkedList(Node* head) {
        Node* newhead = clone(head);
        unordered_map<Node*, Node*> mapping;

        Node* temp1 = head;
        Node* temp2 = newhead;

        while (temp1 != NULL && temp2 != NULL) {
            mapping[temp1] = temp2;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        temp1 = head;
        temp2 = newhead;

        while (temp1 != NULL) {
            temp2->random = mapping[temp1->random];
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return newhead;
    }
};

// Helper function to print list with random pointers
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << "Node data: " << temp->data;
        if (temp->random)
            cout << ", Random points to: " << temp->random->data;
        else
            cout << ", Random points to: NULL";
        cout << endl;
        temp = temp->next;
    }
}

// Main function
int main() {
    // Creating original linked list: 1 -> 2 -> 3
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    // Setting random pointers
    head->random = head->next->next;           // 1's random -> 3
    head->next->random = head;                 // 2's random -> 1
    head->next->next->random = head->next;     // 3's random -> 2

    // Cloning the list
    Solution sol;
    Node* clonedHead = sol.cloneLinkedList(head);

    // Print original list
    cout << "Original list:\n";
    printList(head);

    cout << "\nCloned list:\n";
    printList(clonedHead);

    return 0;
}
