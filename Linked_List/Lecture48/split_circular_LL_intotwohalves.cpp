#include <iostream>
using namespace std;



 
class Node {

    public:
    int data;
    Node* next;

    Node(int data){
        this-> data = data;
        this -> next = NULL; 
    }

};



void print(Node* tail){
    if (tail == NULL) return;

    Node* temp = tail;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail);
    cout << endl; 
}

int getcount(Node* head){
     
    Node* temp = head;
    int count=1;
    while(temp->next != head){
          count++;
          temp = temp -> next;
    }

    return count;
}

void split(Node* head, Node*& head1, Node*& head2) {
    if (head == NULL) return;

    int count = getcount(head);
    int half = count / 2+ 1;

    Node* temp = head;
    int i = 1;
    while (i < half) {
        temp = temp->next;
        i++;
    }

 
    head1 = head;
    head2 = temp->next;

    Node* tail1 = temp;
    Node* tail2 = head2;

    // Complete first circular list
    tail1->next = head1;

    // Traverse to last node of second list
    while (tail2->next != head) {
        tail2 = tail2->next;
    }

    // Complete second circular list
    tail2->next = head2;
}



void insertnode( Node* &tail, int element, int d){
     //asssuming that the element is present in the list

     //empty list
     if(tail == NULL){
        Node* newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode;
     }
     else{
        //non-empty list
        Node* curr = tail;

        
        while(curr-> data != element ){
            curr = curr -> next;               
        }

        Node* temp = new Node(d);
        temp -> next = curr -> next;
        curr -> next = temp;
     }
      
}

    

int main() {
    Node *tail = NULL;

    insertnode(tail, 5, 3);
    insertnode(tail, 3, 10);
    insertnode(tail, 10, 9);
    insertnode(tail, 3, 11);
    insertnode(tail, 3, 56);

    cout << "Original list: ";
    print(tail);

    cout << "Count is: " << getcount(tail) << endl;

    Node* head1 = NULL;
    Node* head2 = NULL;

    split(tail, head1, head2);

    cout << "First half: ";
    print(head1);

    cout << "Second half: ";
    print(head2);

    return 0;
}
