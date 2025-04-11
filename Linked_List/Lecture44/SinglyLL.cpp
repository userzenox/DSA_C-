#include <iostream>
using namespace std;



//SINGLY 
class Node {

    public:
    int data;
    Node* next;

    Node(int data){
        this-> data = data;
        this -> next = NULL; 
    }

    // Node(int data, Node* next){
    //     this-> data = data;
    //     this -> next = NULL;
    // }

    //destructor
    ~Node(){
        int value = this-> data;
        //memory free
        if(this->next != NULL){
            delete next;
            this -> next = NULL;
        }
        cout << "memory is free for node with data " << value << endl;
    }
};



void InsertAtHead(Node* &head, int d){
    //new node create
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}
 
void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp-> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

void InsertAtTail(Node* &tail, int d){
    //new node create
    Node* temp = new Node(d);
     tail-> next = temp;
     tail = temp;
}

void InsertAtPosition( Node* &head, Node* &tail, int position, int d){
     
    //Inserting at head
    if(position == 1){
        InsertAtHead(head,d);
        return;   // used to stop the code here.
    }

    Node* temp = head;
    int count =1;

    while(  count < position){
        temp = temp-> next;
        count++;
    }

      //Inserting at last position
      if(temp -> next == NULL){
        InsertAtTail(tail,d);
        return;
      }

    //creating a node for d
    Node* nodeToInsert = new Node(d);
    nodeToInsert-> next = temp->next;
       temp->next = nodeToInsert;
      
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
    //  cout << node1 -> data << endl; 
    //  cout << node1-> next << endl;

     Node* head = node1;
     Node* tail = node1;
     cout << "head is " << head << endl;
     print(head);

     InsertAtHead(head,12);

     print(head);

     
     InsertAtTail(tail,32);

     print(head);
     
     InsertAtPosition(head,tail,3,22);
     print(head);

     InsertAtPosition(head,tail,1,0);
     print(head);

     InsertAtPosition(head,tail,5,1000);
     print(head);

     deleteNote(1,head);
     print(head);

     deleteNote(3,head);
     print(head);


    return 0;
}