#include <iostream>
#include <unordered_map>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* clone(Node* head) {
        if (head == NULL) return NULL;

        Node* temp = head;
        Node* clonehead = NULL;
        Node* clonetail = NULL;

        while (temp != NULL) {
            Node* newNode = new Node(temp->val);
            if (clonehead == NULL) {
                clonehead = newNode;
                clonetail = newNode;
            } else {
                clonetail->next = newNode;
                clonetail = newNode;
            }
            temp = temp->next;
        }
        return clonehead;
    }

    void point(Node*& head, Node*& newhead) {
        Node* temp1 = head;
        Node* temp2 = newhead;

        while (temp1 != NULL) {
            Node* next = temp1->next;
            temp1->next = temp2;
            temp1 = next;

            next = temp2->next;
            temp2->next = temp1;
            temp2 = next;
        }
    }

    Node* copyRandomList(Node* head) {
        Node* newhead = clone(head);
        point(head, newhead);

        Node* temp = head;
        while (temp != NULL) {
            if (temp->next != NULL && temp->random != NULL) {
                temp->next->random = temp->random->next;
            }
            temp = temp->next ? temp->next->next : nullptr;
        }

        Node* temp1 = head;
        Node* temp2 = newhead;
        while (temp1 != NULL && temp2 != NULL) {
            temp1->next = temp2->next;
            temp1 = temp1->next;

            if (temp1 == NULL) break;

            temp2->next = temp1->next;
            temp2 = temp2->next;
        }

        return newhead;
    }
};

// Helper to print the list with random pointers
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << "Val: " << temp->val;
        if (temp->random) {
            cout << ", Random: " << temp->random->val;
        } else {
            cout << ", Random: NULL";
        }
        cout << endl;
        temp = temp->next;
    }
}

int main() {
    // Creating a list: 1 -> 2 -> 3
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    // Setting up random pointers
    head->random = head->next->next;        // 1's random -> 3
    head->next->random = head;              // 2's random -> 1
    head->next->next->random = head->next;  // 3's random -> 2

    cout << "Original list:\n";
    printList(head);

    Solution solution;
    Node* clonedHead = solution.copyRandomList(head);

    cout << "\nCloned list:\n";
    printList(clonedHead);

    return 0;
}
