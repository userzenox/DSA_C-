#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack <string> s;


// last in first out.
    s.push("kumar");
    s.push("Piyush");
    s.push("Dimple");

   cout << "top element - " << s.top() << endl;

    s.pop();
       cout << "top element after pop - " << s.top() << endl;

   cout << "Size of stack -  "  << s.size() << endl;

}