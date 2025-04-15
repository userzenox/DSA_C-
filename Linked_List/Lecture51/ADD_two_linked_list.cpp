#include <iostream>
#include <vector>
using namespace std;

/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/* The Solution class goes here (as we discussed previously) */
class Solution {
public:
    void insertAtTail(ListNode*& head, ListNode*& tail, int digit) {
        ListNode* temp = new ListNode(digit);
        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    ListNode* reverse(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        while (curr != NULL) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    ListNode* add(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* ansHead = NULL;
        ListNode* ansTail = NULL;

        while (l1 != NULL || l2 != NULL || carry != 0) {
            int val1 = (l1 != NULL) ? l1->val : 0;
            int val2 = (l2 != NULL) ? l2->val : 0;

            int sum = carry + val1 + val2;
            int digit = sum % 10;
            carry = sum / 10;

            insertAtTail(ansHead, ansTail, digit);

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        return ansHead;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* rev1 = reverse(l1);
        ListNode* rev2 = reverse(l2);
        ListNode* result = add(rev1, rev2);
        return reverse(result);
    }
};

/* Helper to create linked list from vector */
ListNode* createList(const vector<int>& nums) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int num : nums) {
        ListNode* newNode = new ListNode(num);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

/* Helper to print linked list */
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

/* Main function */
int main() {
    vector<int> v1 = {9, 9, 9, 9, 9, 9, 9};
    vector<int> v2 = {9, 9, 9, 9};

    ListNode* l1 = createList(v1);
    ListNode* l2 = createList(v2);

    Solution sol;
    ListNode* result = sol.addTwoNumbers(l1, l2);

    cout << "Result: ";
    printList(result);

    return 0;
}
