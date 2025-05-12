#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    void reverseQueue(queue<int> &q) {
        if (q.empty()) return;

        int front = q.front();
        q.pop();

        // Recursive call
        reverseQueue(q);

        // Add the front element back after recursion
        q.push(front);
    }
};

int main() {
    queue<int> q;

    // Inserting elements into the queue
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    Solution sol;
    sol.reverseQueue(q);

    // Display the reversed queue
    cout << "Reversed Queue: ";
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
