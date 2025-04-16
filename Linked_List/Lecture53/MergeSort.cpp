#include <iostream>
using namespace std;

// Definition for singly-linked list node
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

    Node* getmid(Node* head){
        if (!head || !head->next) return head;
        Node* fast = head->next;
        Node* slow = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    Node* merge(Node* left, Node* right) {
        if (left == NULL) return right;
        if (right == NULL) return left;

        Node* ans = new Node(-1);
        Node* temp = ans;

        while (left != NULL && right != NULL) {
            if (left->data < right->data) {
                temp->next = left;
                temp = left;
                left = left->next;
            } else {
                temp->next = right;
                temp = right;
                right = right->next;
            }
        }

        while (left != NULL) {
            temp->next = left;
            temp = left;
            left = left->next;
        }

        while (right != NULL) {
            temp->next = right;
            temp = right;
            right = right->next;
        }

        return ans->next;
    }

    Node* mergeSort(Node* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        Node* mid = getmid(head);
        Node* left = head;
        Node* right = mid->next;
        mid->next = NULL;

        left = mergeSort(left);
        right = mergeSort(right);

        return merge(left, right);
    }
};

// Helper function to print a linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a linked list from an array
Node* createList(int arr[], int n) {
    if (n == 0) return NULL;
    Node* head = new Node(arr[0]);
    Node* tail = head;
    for (int i = 1; i < n; ++i) {
        tail->next = new Node(arr[i]);
        tail = tail->next;
    }
    return head;
}

int main() {
    int arr[] = {3, 5, 4, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* head = createList(arr, n);

    cout << "Original list: ";
    printList(head);

    Solution sol;
    head = sol.mergeSort(head);

    cout << "Sorted list: ";
    printList(head);

    return 0;
}
