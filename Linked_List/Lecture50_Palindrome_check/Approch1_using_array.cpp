#include <iostream>
#include <vector>
using namespace std;

// Node definition
struct Node {
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Solution {
  public:
  bool checkPalindrome(vector<int> &arr){
    int e = arr.size() - 1;
    int s = 0;

    while (s <= e) {
        if (arr[s] != arr[e]) {
            return false;
        }
        s++;
        e--;
    }
    return true;
  }

  // Function to check whether the list is palindrome.
  bool isPalindrome(Node *head) {
    vector<int> arr;
    Node* temp = head;

    while (temp != NULL) {
        arr.push_back(temp->data);
        temp = temp->next;
    }

    return checkPalindrome(arr);
  }
};

int main() {
    // Example: Palindromic linked list
    int arr[] = {1, 2, 3, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Creating linked list
    Node* head = new Node(arr[0]);
    Node* current = head;
    for (int i = 1; i < n; ++i) {
        current->next = new Node(arr[i]);
        current = current->next;
    }

    // Check if it's a palindrome
    Solution sol;
    if (sol.isPalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}
