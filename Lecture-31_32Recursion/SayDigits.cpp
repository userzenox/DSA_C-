#include<iostream>
using namespace std;

void sayDigit( int n, string arr[10]){
     
    if(n==0){
        return ;
    }

    int d = n%10;
      n = n/10;

      sayDigit(n,arr);

      cout << arr[d] << " ";
}

int main(){

    string arr[10] = {"zero", "one", "two", "three",
        "four", "five", "six",
        "seven", "eight", "nine"};


    int n;
    cout<< "Enter the number" << endl;
    cin >> n;

     sayDigit(n,arr);
   return 0;
}