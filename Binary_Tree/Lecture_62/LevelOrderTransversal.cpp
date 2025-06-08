//first assume  levels
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class node{
   public: 
         int data;
         node* left;
         node* right;

         node(int d){
            this -> data = d;
            this -> left = NULL;
            this -> right = NULL;
         }
};



void levelOrdertraversal(node* root){
    queue <node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
      
        node* temp = q.front();
        q.pop();
        if(temp == NULL){
           cout << endl;
           if(!q.empty()){
              q.push(NULL); 
           }
        }  
        else{

         cout << temp -> data << " "; 
   //if temp->left is not NULL 
        if(temp -> left){
           q.push(temp -> left);
        }

        if(temp -> right){
          q.push(temp -> right);
        }
        }


     
    }
}

void reverseLevelOrderTraversal(node* root) {
    if(root == NULL) return;

    queue<node*> q;
    stack<node*> s;

    q.push(root);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        s.push(temp);

        // Enqueue right first, then left (to reverse it later)
        if(temp->right) q.push(temp->right);
        if(temp->left) q.push(temp->left);
    }

    // Print stack contents
    while(!s.empty()) {
        cout << s.top()->data << " ";
        s.pop();
    }
}


int main() {
    // Constructing a larger tree manually

    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    root->left->right->left = new node(8);
    root->right->right->right = new node(9);

    cout << "Level Order Traversal of the Tree:" << endl;
    levelOrdertraversal(root);

    cout << endl;
    reverseLevelOrderTraversal(root);
    return 0;
}
