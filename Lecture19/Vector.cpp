#include<iostream>
#include<vector>
using namespace std;

int main(){
    
    vector<int> v;

    vector <int> a(5,1);
       cout << " printing vector a" << endl;
    for(int i:a){
        cout << i << " ";
    }
   cout << endl;
    vector <int> last(a);
    cout << " printing vector copy of  " << endl;
    for(int i:last){
        cout << i << " ";
    }

    cout << endl<< "capacity : " << v.capacity() << endl;

    v.push_back(1);
    cout << "capacity : " << v.capacity() << endl;

    v.push_back(2);
    cout << "capacity : " << v.capacity() << endl;
    
    v.push_back(3);
    cout << "capacity : " << v.capacity() << endl;
    cout<< "size is : " << v.size() << endl;
     
    cout << "Element at 2nd index - " << v.at(2) << endl;

    cout << "befoe pop" << endl;
    for(int i:v){
        cout << i << " ";
    }
    cout << endl;

    v.pop_back();

     cout << "after pop" << endl;
    for(int i:v){
        cout << i << " ";
    }
    cout << endl;

    v.clear();
    cout << "after clear size" << v.size() << endl;


    return 0;
}