#include<iostream>
#include<queue>
using namespace std;

int main() {
    // create a queue
    queue<int> q;

    q.push(11);
    q.push(15);
    cout << "Front of Queue is:" << q.front() << endl;
    q.push(13);

    cout << "size of queue is : " << q.size() << endl;

    q.pop();
    cout << "Front of Queue is after 1st pop:" << q.front() << endl;
    q.pop();
    q.pop();

    cout << "size of queue is : " << q.size() << endl;

    if(q.empty()) {
        cout << "Queue is empty " << endl; // If I pop() 3 times then it will give empty
    }
    else {
        cout << "queue is not empty " << endl;
    }
}
