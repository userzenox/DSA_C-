#include<iostream>
using namespace std;

int main(){
    
    int i = 5;
    int *p = &i;
    int **p2 = &p;


    cout << "printing p - " << p << endl;
    cout << "printing *p2 - " << *p2 << endl;
    cout << "printing p2 - " << p2 << endl;
    cout << "address of &p - " << &p << endl;


    //printing value of i
    cout << "printing value of i" << endl;
    cout << i << endl;
    cout << *p << endl;
    cout << **p2 << endl;



    cout << "printing address of i" << endl;
    cout << &i << endl;
    cout << p << endl;
    cout << *p2 << endl;


    
    cout << "printing address of p" << endl;
    cout << &p << endl;
    cout << p2 << endl;
  




    return 0;
}