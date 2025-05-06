#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

// Function to sort the linked list of 0s, 1s, and 2s
Node* sortList(Node *head){
    int countone = 0;
    int counttwo = 0;
    int countzero = 0;
    Node * temp = head;
    while(temp != NULL ){
        if(temp->data ==  0){
            countzero++;
        }
        else  if(temp->data ==  1){
            countone++;
        }
         else  if(temp->data ==  2){
            counttwo++;
        }
        temp = temp->next;
    }

    temp = head;
    while(temp !=NULL){
        if(countzero !=0){
            temp->data = 0;
            countzero--;
        }
        else if(countone!=0){
            temp-> data = 1;
            countone--;
        }
        else if(counttwo !=0){
             temp-> data = 2;
            counttwo--;
        }
        temp = temp->next;
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

// Helper function to insert node at the end
void insertAtTail(Node* &head, int val) {
    if (head == NULL) {
        head = new Node(val);
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new Node(val);
}

int main() {
    Node* head = NULL;

    // Create a list: 1 -> 0 -> 2 -> 1 -> 2 -> 0 -> 1
    insertAtTail(head, 1);
    insertAtTail(head, 0);
    insertAtTail(head, 2);
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 0);
    insertAtTail(head, 1);

    cout << "Original list: ";
    printList(head);

    head = sortList(head);

    cout << "Sorted list: ";
    printList(head);

    return 0;
}
