#include<iostream>
using namespace std;

int main(){
   int num = 5;

   cout << num << endl;

   // Address of operator - &

   cout << " Address of num is " << &num << "Its in hexa decimal form" << endl ;


   int *ptr = &num;

   cout << "value of *ptr" << *ptr << endl;
   cout << "Address of ptr" << ptr << endl;

   double n = 4.55;
   double *p = &n;

   cout << "value of *p" << *p << endl;
   cout << "Address of p" << p << endl;

    cout << " size of integer is " << sizeof(num) << endl;
    cout << " size of integer is " << sizeof(ptr) << endl;
    cout << " size of integer is " << sizeof(p) << endl;


    //o=pointer to int is created and pointing to some garbage value
    //  int *p ;

    // so initialise it to zero 
      int *z = 0;
      cout << *z << endl;

    return 0;
}