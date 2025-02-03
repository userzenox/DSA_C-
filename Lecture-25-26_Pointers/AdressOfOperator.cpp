#include<iostream>
using namespace std;

int main(){
   int num = 5;

   cout << num << endl;

   // Address of operator - &

   cout << " Address of num is " << &num << "Its in hexa decimal form" << endl ;


   int *ptr = &num;

   cout << "value of *ptr - " << *ptr << endl;
   cout << "Address of ptr - " << ptr << endl;

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
      // int *z = 0;
      // cout << *z << endl;

// we can also initialize in this way
      int *pi =0;
      pi = &num;

      //its same as 
      int *q = &num;


      cout << pi << endl;
      cout << *pi << endl;
       cout << q << endl;
      cout << *q << endl;


      //how n value is changed 

      int x = 5;
      int *po = &x;
      
       cout << "before modifying *po - " << x << endl;

      *po = *po + 5;

      cout << "after modifying *po - " << x << endl;


     //copying a pointer 
     int *npo = po;
     cout << po << " - " << npo << endl;
     cout << *po << " - " << *npo << endl;


     // important concept
      int i =3;
      int *t = &i;
      cout << "value of *t++ - "<< *t++ << endl;
      // now the *t is incremented to new memory location and some garbage value is seen
      cout << "value of *t - " << *t << endl;
      cout << "value of ++*t - "<< ++*t << endl;

      cout << " value of t " << t<< endl;
      cout << " value of t " << t+1<< endl;


      char c = 'e';
      char *cp = &c;
      cout << cp << endl;
      cp =cp +1;
       cout << cp <<" value" << endl;


       *cp = *cp+ 1;
      cout << "value of *cp " << *cp;

    return 0;
}