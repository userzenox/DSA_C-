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

void inorder(node* root){
      //base case
      if(root == NULL){
         return  ;    
        }
      
        inorder(root->left);
        cout << root-> data << " ";
        inorder(root->right);

      }



int main() {
    // Constructing a larger tree manually

    node* root = new node(1);
    root->left = new node(3);
    root->right = new node(5);

    root->left->left = new node(7);
    root->left->right = new node(11);
    root->right->left = new node(17);


   

    cout << "inorder traversal is" << endl;
    inorder(root);
   
    return 0;
}
