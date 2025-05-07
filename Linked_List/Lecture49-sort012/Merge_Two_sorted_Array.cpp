#include <iostream>
using namespace std;

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/
template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T data) {
        next = NULL;
        this->data = data;
    }

    ~Node() {
        if (next != NULL) {
            delete next;
        }
    }
};

// Merge helper function
Node<int>* solve(Node<int>* first, Node<int>* second){
    Node<int>* curr = first->next;
    Node<int>* prev = first;
    Node<int>* temp = second;

    while(temp != NULL && curr != NULL){
        if(prev->data <= temp->data && temp->data <= curr->data){
            Node<int>* forward = temp->next;
            prev->next = temp;
            temp->next = curr;
            temp = forward;
            prev = prev->next;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }

    if(temp != NULL){
        prev->next = temp;
    }

    return first;
}

// Merge two sorted lists
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(first == NULL) return second;
    if(second == NULL) return first;

    if(first->data <= second->data){
        return solve(first, second);
    } else {
        return solve(second, first);
    }
}

// Helper to print a linked list
void printList(Node<int>* head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper to insert at the end
Node<int>* insertTail(Node<int>* head, int value) {
    if(head == NULL) return new Node<int>(value);

    Node<int>* temp = head;
    while(temp->next != NULL) temp = temp->next;

    temp->next = new Node<int>(value);
    return head;
}

int main() {
    // First sorted list: 1 -> 4 -> 5
    Node<int>* first = NULL;
    first = insertTail(first, 1);
    first = insertTail(first, 4);
    first = insertTail(first, 5);

    // Second sorted list: 2 -> 3 -> 6
    Node<int>* second = NULL;
    second = insertTail(second, 2);
    second = insertTail(second, 3);
    second = insertTail(second, 6);

    cout << "First List: ";
    printList(first);
    cout << "Second List: ";
    printList(second);

    // Merge and print
    Node<int>* merged = sortTwoLists(first, second);
    cout << "Merged List: ";
    printList(merged);

    // Cleanup memory
    delete merged;

    return 0;
}
