#include <bits/stdc++.h>
using namespace std;

class CircularQueue {
    int* arr;
    int front;
    int rear;
    int size;

public:
    CircularQueue(int n) {
        arr = new int[n];
        front = -1;
        rear = -1;
        size = n;
    }

    bool enqueue(int value) {
        if ((rear + 1) % size == front) {
            // Queue is full
            cout << "Queue is full. Cannot enqueue " << value << endl;
            return false;
        }

        if (front == -1) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }

        arr[rear] = value;
        return true;
    }

    int dequeue() {
        if (front == -1) {
            // Queue is empty
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1;
        }

        int ans = arr[front];
        arr[front] = -1;

        if (front == rear) {
            // Only one element
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }

        return ans;
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q(5);  // Queue of size 5

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);  // This should fail (queue full)

    q.display();

    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;

    q.display();

    q.enqueue(60);
    q.enqueue(70);  // Should fill remaining slots

    q.display();

    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;

    q.display();

    return 0;
}
