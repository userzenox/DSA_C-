#include <iostream>
using namespace std;


 
class Deque
{
  
public:
       int *arr;
    int size;
    int front;
    int rear;
    // Initialize your data structure.
   
    Deque(int n)
    {
        // Write your code here.
         arr = new int[n];
         size =n;
         front =-1;
         rear =-1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
       
        // Write your code here.
        if(rear%(size-1) == (front-1) || (front==0&&(rear==size-1))){
             return false;
        }

        else if(front==-1){
            rear = 0;
            front =0;
        }

         else if(front ==0){
            front = size-1;
        }
        
        else{
            front--;
        }
         arr[front] = x;
        return true;

    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
       
        // Write your code here.
          if(rear%(size-1) == (front-1) || (front==0&&(rear==size-1))){
             return false;
        }

        if(rear==-1){
            rear = 0;
            front =0;
        }

        else if(rear == size-1 ){
            rear =0 ;
        }
        
        else{
            rear++;
        }
          arr[rear] = x;
        return true;

    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        // Write your code here.
      
         if(front==-1){
             return -1;
         }

           int ans = arr[front];
        arr[front] =-1;

       
        if(front == rear){
            rear=front=-1;        
        }

        else if(front== size-1 ){
            front = 0;
        }else{
            front++;
        }
        return ans;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        // Write your code here.
         if(front==-1){
             return -1;
         }
         
        int ans = arr[rear];
        arr[rear] =-1;
       
        if(rear == front){
            rear=front=-1;        
        }

        else if(rear== 0 ){
            rear = size-1;
        }else{
            rear--;
        }
        return ans;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        // Write your code here.
        if(front==-1){
             return -1;
         }

         return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        // Write your code here.
        if(front==-1){
             return -1;
         }

         return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        // Write your code here.
         if(front==-1){
             return true;
         }
         return false;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        // Write your code here.
          if(rear%(size-1) == (front-1) || (front==0&&(rear==size-1))){
             return true;
        }
        return false;
    }
};

int main() {
    Deque dq(5); // Create a deque of size 5

    cout << "Push rear 10: " << dq.pushRear(10) << endl;
    cout << "Push rear 20: " << dq.pushRear(20) << endl;
    cout << "Push front 5: " << dq.pushFront(5) << endl;
    cout << "Push front 3: " << dq.pushFront(3) << endl;

    cout << "Front element: " << dq.getFront() << endl;
    cout << "Rear element: " << dq.getRear() << endl;

    cout << "Pop rear: " << dq.popRear() << endl;
    cout << "Pop front: " << dq.popFront() << endl;

    cout << "Is empty: " << dq.isEmpty() << endl;
    cout << "Is full: " << dq.isFull() << endl;

    cout << "Push rear 30: " << dq.pushRear(30) << endl;
    cout << "Push rear 40: " << dq.pushRear(40) << endl;
    cout << "Push rear 50: " << dq.pushRear(50) << endl; // Should fail if deque is full

    cout << "Front: " << dq.getFront() << endl;
    cout << "Rear: " << dq.getRear() << endl;

    return 0;
}
