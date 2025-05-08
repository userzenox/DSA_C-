#include <iostream>
using namespace std;

class Queue {
    int *arr;
    int front;
    int rear;
    int size;

public:
    Queue(int s = 100) {
        size = s;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    bool isEmpty() {
        return front == rear;
    }

    void enqueue(int data) {
        if (rear == size) {
            cout << "Queue is full" << endl;
            return;
        }
        arr[rear] = data;
        rear++;
    }

    int dequeue() {
        if (front == rear) {
            return -1;
        }
        int val = arr[front];
        arr[front] = -1;
        front++;
        if (front == rear) {
            front = 0;
            rear = 0;
        }
        return val;
    }

    int frontValue() {
        if (front == rear) return -1;
        return arr[front];
    }
};

int main() {
    Queue q(5);  // create queue with size 5
    q.enqueue(10);
    q.enqueue(20);
    cout << "Front element: " << q.frontValue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}

