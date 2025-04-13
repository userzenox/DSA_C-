#include <iostream>
#include <map>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// 1. Detect loop using map
bool Detectloop(Node* head) {
    map<Node*, bool> visited;
    Node* temp = head;

    while (temp != NULL) {
        if (visited[temp]) {
            return true;
        }
        visited[temp] = true; // FIXED: must mark the current node as visited before moving
        temp = temp->next;
    }

    return false;
}

// 2. Floyd’s Cycle Detection
Node* FCDLoop(Node* head) {
    if (head == NULL) return NULL;

    Node* fast = head;
    Node* slow = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return slow;  // Loop detected
        }
    }

    return NULL;
}

// 3. Get starting node of the loop
Node* getStarting(Node* head) {
    Node* intersection = FCDLoop(head);
    if (intersection == NULL) return NULL;

    Node* slow = head;

    while (slow != intersection) {
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;
}

// 4. Remove loop
Node* removeLoop(Node* head) {
    if (head == NULL) return NULL;

    Node* start = getStarting(head);
    if (start == NULL) return head; // No loop

    Node* temp = start;
    while (temp->next != start) {
        temp = temp->next;  // FIXED: was not updating temp
    }

    temp->next = NULL;  // Break the loop
    return head;
}

// 5. Print linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// 6. Main to test
int main() {
    // Create nodes
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Create loop: 5 -> 3
    head->next->next->next->next->next = head->next->next;

    // Detect loop before removal
    if (Detectloop(head)) {
        cout << "Loop detected using map!" << endl;
    }

    if (FCDLoop(head)) {
        cout << "Loop detected using Floyd’s algorithm!" << endl;
    }

    // Remove loop
    head = removeLoop(head);

    // Check again
    if (!Detectloop(head)) {
        cout << "Loop removed successfully!" << endl;
    }

    // Print list
    printList(head);

    return 0;
}
