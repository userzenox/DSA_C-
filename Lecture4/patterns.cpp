#include <iostream>
using namespace std;

int main() {
    
  
    //    int n;
    //    cin >> n;
    //    int i=1;
    //    while(i<=n){
    //     cout << " "<< i;
    //     i = i + 1;
    //    }
    

    /* Star pattern*/
    //  int n;
    //    cin >> n;
    //    int i=1;
      
    //    while(i<=n){
        
    //      int j=n-i+1;
    //     while(j<=n){
    //          cout << "*";
    //          j= j+1;
    //     }
    //      cout << endl;
    //      i=i+1;
       
    //    }

    

     /*Number pattern*/
      //  int n;
      //  cin >> n;
      //  int i=1;
      
      //  while(i<=n){
      //   int a=1;
      //    int j=n-i+1;
      //   while(j<=n){
      //        cout << a ;
      //        j= j+1;
      //        a=a+1;
      //   }
      //    cout << endl;
      //    i=i+1;
      //  }

    //  int n;
    //    cin >> n;
    //    int i=1;
      
    //    while(i<=n){
    //     int a=1;
    //      int j=n-i+1;
    //     while(j<=n){
    //          cout << i ;
    //          j= j+1;
    //          a=a+1;
    //     }
    //      cout << endl;
    //      i=i+1;
    //    }


    //Character patterns
    //  int n;
    //    cin >> n;
    //    int i=1;
     
    //    while(i<=n){
      
    //     int j = 1;
    //     while(j<=n){
    //         char ch = 'A'  + i -1;
    //          cout << ch;
    //          j= j+1;
    //     }
      
    //     i = i+ 1;
    //     cout << endl;
        
    //    }

    // int n;
    //    cin >> n;
    //    int i=1;
    //    int a=1;
    //    while(i<=n){
        
    //     int j = 1;
       
    //     while(j<=n){
    //         char ch = 'A' + a -1;
    //          cout << ch;
    //          j= j+1;
    //          a  = a +1;
    //     }
      
    //     i = i+ 1;
    //     cout << endl;
         
    //    }


// complex pattern

//     int n;
//        cin >> n;
//        int i=1;
//        while(i<=n){
//         int j = 1;
//         while(j<=i){
//             char ch = 'A' + i -1;
//              cout << ch;
//              j= j+1;
//         }
//         i = i+ 1;
//         cout << endl;
//        }
//     return 0;
// }

//  int n;
//        cin >> n;
//        int i=1;
//        while(i<=n){
//         int j = 1;
//         while(j<=i){
//             char ch = 'A' + i + j -2 ;
//              cout << ch;
//              j= j+1;
//         }
//         i = i+ 1;
//         cout << endl;
//        }
//     return 0;
// }

//  int n;
//        cin >> n;
//        int i=1;
//        while(i<=n){
//         int j = 1;
//         char start = 'A' + n -i;
//         while(j<=i){
            
//              cout << start;
//              start = start +1;
//              j= j+1;
//         }
//         i = i+ 1;
//         cout << endl;
//        }


/* Space varient*/
//   int n;
//   cin >> n;
//   int i=1;
//   int space;
//   while(i<=n){
//           space = n - i ;
//           while(space){
//              cout << " ";
//              space = space -1; 
//           }
//     int j =1;
//      while(j<=i){ 
//            cout << '*';
            
//            j=j+1;
//      }
//     i=i+1;
//     cout << endl;

//   }

 int n;
  cin >> n;
  int i=1;
  int space;
  while(i<=n){
      space =  n - i ;
          while(space){
             cout << " ";
             space = space - 1; 
          }
    
       int j = 1;
       while (j<=i){
         cout<< j;
         j= j+1;
       }

       int start = i -1;
       while(start){
           cout <<start;
           start = start - 1;
       }
   
    i=i+1;
    cout << endl;
  }

    return 0;
}


