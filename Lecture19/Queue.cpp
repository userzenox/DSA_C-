#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue <string> q;


// last in first out.
    q.push("kumar");
    q.push("Piyush");
    q.push("Dimple");

   cout << "top element - " << q.front() << endl;

     q.pop();
     cout << "top element after pop - " << q.front() << endl;

   cout << "Size of stack -  "  << q.size() << endl;
    
}