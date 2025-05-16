#include <iostream>
#include <queue>
using namespace std;

void interleaveQueue(queue<int>& q) {
    if (q.size() % 2 != 0) {
        cout << "Queue size must be even." << endl;
        return;
    }

    int halfSize = q.size() / 2;
    queue<int> firstHalf;

    // Step 1: Push first half into a separate queue
    for (int i = 0; i < halfSize; ++i) {
        firstHalf.push(q.front());
        q.pop();
    }

    // Step 2: Interleave the two halves
    while (!firstHalf.empty()) {
        q.push(firstHalf.front()); // element from first half
        firstHalf.pop();

        q.push(q.front());         // element from second half
        q.pop();
    }
}

int main() {
    queue<int> q;

    // Example input: {1, 2, 3, 4, 5, 6}
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    interleaveQueue(q);

    // Output the interleaved queue
    cout << "Interleaved Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
