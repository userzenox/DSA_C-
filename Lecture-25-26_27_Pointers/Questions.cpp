#include<iostream>
using namespace std;

void update(int *p){
     cout << endl << *p << endl;
    *p = (*p) * 2;
   
}

int main(){
    // int i = 10;
    // // int *p = &i;
    // // update(p);
    //  // its same as
    // update(&i);
    // cout << i << endl;
    // return 0;

// //question2
// int first = 110;
// int *p = &first;
// int **q = &p;
// int second = (**q)++ + 9;
// cout << first << " " << second << endl;


//amazing question 3
int first = 100;
int *p = &first;
int **q = &p;
int second = ++(**q);
int *r = *q;
++(*r);
cout << first << " " << second << endl;

return 0;


return 0;

}