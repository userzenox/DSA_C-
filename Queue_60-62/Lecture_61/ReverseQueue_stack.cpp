#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Solution {
  public:
    queue<int> reverseQueue(queue<int> &q) {
        stack<int> st;
        
        while(!q.empty()){
            st.push(q.front());
            q.pop();
        }
        
        while(!st.empty()){
            q.push(st.top());
            st.pop();
        }
        
        return q;
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
    queue<int> reversedQ = sol.reverseQueue(q);
    
    // Display the reversed queue
    cout << "Reversed Queue: ";
    while(!reversedQ.empty()) {
        cout << reversedQ.front() << " ";
        reversedQ.pop();
    }
    cout << endl;

    return 0;
}
