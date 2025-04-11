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



void print(Node* tail){
    if (tail == NULL) return;

    Node* temp = tail;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail);
    cout << endl; 
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

          // element is the data where you want to insert the new data next
        while(curr-> data != element ){
            curr = curr -> next;               
        }

        Node* temp = new Node(d);
        temp -> next = curr -> next;
        curr -> next = temp;
     }
      
}

void deleteNode(Node* &tail, int value) {

    // empty List
    if(tail == NULL) {
        cout << "List is empty, please check again" << endl;
        return;
    }
    else {
        // non-empty
    
        // assuming that "value" is present in the Linked List
        Node* prev = tail;
        Node* curr = prev -> next;
    
        while(curr -> data != value) {
            prev = curr;
            curr = curr -> next;

        }
    
        prev -> next = curr -> next;

         // 1 node linked list
         if(curr == prev){
            tail = NULL;
        }

        // 2 node linked list
        if(tail == curr ){
            tail = prev;
        }
        curr -> next = NULL;
        delete curr;
    }
}
    

int main() {
    
    Node * tail = NULL;

    insertnode(tail,5,3);
    print(tail);

    insertnode(tail,3,10);
    print(tail);

    insertnode(tail,10,9);
    print(tail);

    insertnode(tail,3,11 );
    print(tail);

    insertnode(tail,3,56);
    print(tail);

    deleteNode(tail,3);
    print(tail);


    return 0;
}