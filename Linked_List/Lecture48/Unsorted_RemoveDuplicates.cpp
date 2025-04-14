#include <bits/stdc++.h>
using namespace std;

/****************************************************************
    Following is the class structure of the Node class:
*****************************************************************/
class Node {
public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

/****************************************************************
    Function to remove duplicates from the linked list:
*****************************************************************/
Node *removeDuplicates(Node *head) {
    if (head == NULL) {
        return NULL;
    }
    
    map<int, bool> visited;
    Node *curr = head;
    Node *prev = NULL;

    while (curr != NULL) {
        if (visited[curr->data] == true) {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        } else {
            visited[curr->data] = true;
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}

/****************************************************************
    Main function to demonstrate the removal of duplicates:
*****************************************************************/
int main() {
    // Creating a linked list with duplicate values
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(10);
    head->next->next->next = new Node(30);
    head->next->next->next->next = new Node(20);

    // Removing duplicates
    head = removeDuplicates(head);

    // Printing the resulting linked list
    Node *current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    // Cleaning up memory
    while (head != NULL) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}