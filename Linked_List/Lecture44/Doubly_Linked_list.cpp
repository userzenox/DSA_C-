#include <iostream>
using namespace std;



//SINGLY 
class Node {

    public:
    int data;
    Node* next;
    Node* prev;

    //constructor
    Node(int d){
        this -> data = d;
        this-> prev = NULL;
        this -> next = NULL;
    }

};

void print(Node* head){
    Node* temp = head;

    while( temp !=NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int getLength(Node* head){
    int len =0;
    Node* temp = head;

    while( temp !=NULL){
        len++;
        temp = temp -> next;
    }
    return len;
}

void insertAtHead(Node* & head, int d){
     Node* temp = new Node(d);
     temp->next = head;
     head-> prev = temp;
     
     head = temp;
}

void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail->next = temp;
    temp->prev = tail ;
    tail = temp;
      
}

void insertAtPosition(Node* &head, Node* &tail, int d, int position) {
    if (position <= 0) {
        cout << "Invalid position." << endl;
        return;
    }

    if (position == 1) {
        insertAtHead(head, d);
        return;
    }

    int count = 1;
    Node* temp = head;
    while (count < position - 1 && temp != NULL) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        cout << "Position is out of bounds." << endl;
        return;
    }

    if (temp->next == NULL) {
        insertAtTail(tail, d); // make sure this updates tail properly
        return;
    }

    Node* newnode = new Node(d);
    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next->prev = newnode;
    temp->next = newnode;
}

void deleteNote(int position, Node* &head){
    //deleting first or start node
    if(position == 1){
         Node* temp = head;
         head = head->next;
         temp -> next = NULL;
         //memory free start node
         delete temp;
    }
    else{
        //deleting middle or last node
        Node* curr = head;
        Node* prev = NULL;

        int count =1;
        while(count < position){
            prev = curr;
            curr = curr-> next;
            count++;
        }

        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;

    }
}




int main() {
     Node* node1 = new Node(10);
     Node* head = node1;
     Node* tail = node1;
     
     print(head);
     getLength(head);

     insertAtHead(head,30);
     print(head);

     insertAtHead(head,25);
     print(head);

     insertAtTail(tail,100);
     print(head);

     insertAtPosition(head,tail,64,2);
     print(head);

    return 0;
}