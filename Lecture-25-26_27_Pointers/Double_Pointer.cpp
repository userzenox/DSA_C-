#include<iostream>
using namespace std;

void update(int **p){
    // p=p+1;  //no change

    *p = *p +1;

    // **p = **p +1;
}

int main(){
    
    int i = 5;
    int *p = &i;
    int **p2 = &p;


    // cout << "printing p - " << p << endl;
    // cout << "printing *p2 - " << *p2 << endl;
    // cout << "printing p2 - " << p2 << endl;
    // cout << "address of &p - " << &p << endl;


    // //printing value of i
    // cout << "printing value of i" << endl;
    // cout << i << endl;
    // cout << *p << endl;
    // cout << **p2 << endl;



    // cout << "printing address of i" << endl;
    // cout << &i << endl;
    // cout << p << endl;
    // cout << *p2 << endl;


    
    // cout << "printing address of p" << endl;
    // cout << &p << endl;
    // cout << p2 << endl;
  
      cout << endl;
      cout << "before " << i << endl;
      cout << "before " << p << endl;
      cout << "before " << p2 << endl;

      update(p2);
      
      cout << "After " << i << endl;
      cout << "After " << p << endl;
      cout << "After " << p2 << endl;



    return 0;
}