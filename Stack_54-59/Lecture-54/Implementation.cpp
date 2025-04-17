#include <iostream>
using namespace std;

class Stack{
    //properties
    public:
    int *arr;
    int top;
    int size;
     
    //behaviour
    Stack(int size){
        this-> size = size; 
        arr = new int[size];
        top = -1;
    }

    void push(int element){
         if(size - top > 1){
            top++;
            arr[top] = element;
         }else{
             cout << "Stack overflow"  << endl;
         }
    }

    void pop(){
         if(top >=0){
            top--;
         }
         else{
            cout << "stack Underflow"  << endl;
         }
    }

    int peek() {
        if(top >= 0)
            return arr[top];
        else {
            cout << "Stack is Empty" << endl;
            return -1;
        }
    }
    
    bool isEmpty() {
        if(top == -1) {
            return true;
        } else {
            return false;
        }
    }
};







int main(){

    Stack st(5);

    st.push(22);
    st.push(43);
    st.push(45);

   

   cout << "peak is " << st.peek() << endl;

   st.pop();
   cout << "peak is " << st.peek() << endl;

   st.pop();
   cout << "peak is " << st.peek() << endl;

   st.pop();
   cout << "peak is " << st.peek() << endl;

   cout << st.isEmpty() << endl;

    // stack<int> s;

    // s.push(2);
    // s.push(3);
    // s.push(7);
    
    // cout << "printing top element " << s.top() << endl;

    // cout << "size is " << s.size() << endl;
}