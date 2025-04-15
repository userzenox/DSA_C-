#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Solution {
private:
    Node* getMid(Node* head) {
        Node* slow = head;
        Node* fast = head->next;

        while(fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

    Node* reverse(Node* head) {
        Node* curr = head;
        Node* prev = NULL;
        Node* forward = NULL;

        while(curr != NULL) {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }

        return prev;
    }

public:
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head) {
        if (head == NULL || head->next == NULL) return true;

        Node* middle = getMid(head);
        Node* temp = middle->next;
        middle->next = reverse(temp); // Reverse the second half

        Node* head1 = head;
        Node* head2 = middle->next;

        while(head2 != NULL) {
            if(head1->data != head2->data) {
                middle->next = reverse(middle->next); // Restore the list
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }

        middle->next = reverse(middle->next); // Restore the list
        return true;
    }
};

// Helper function to create a linked list from an array
Node* createList(int arr[], int n) {
    if (n == 0) return NULL;
    Node* head = new Node(arr[0]);
    Node* current = head;
    for (int i = 1; i < n; ++i) {
        current->next = new Node(arr[i]);
        current = current->next;
    }
    return head;
}

int main() {
    int arr[] = {1, 2, 3, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    Node* head = createList(arr, n);
    Solution sol;

    if (sol.isPalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}
