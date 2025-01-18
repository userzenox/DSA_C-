#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

    vector<int> v;
    v.push_back(1);
    v.push_back(4);
    v.push_back(5);
    v.push_back(8);
    v.push_back(5);

       for(int i:v){
        cout << i << " " ;
    }
    cout << endl;
    // Sort the vector
    sort(v.begin(), v.end());
    
    for(int i:v){
        cout << i << " " ;
    }
    cout << endl;

    cout << "finding 6 -> " << binary_search(v.begin(), v.end(), 6) << endl;
    cout << "finding 8 -> " << binary_search(v.begin(), v.end(), 8) << endl;

    // cout << "lower bound-> " << lower_bound(v.begin(), v.end(), 5) << endl;
    // cout << "upper bound-> " << upper_bound(v.begin(), v.end(), 5) << endl;

     int a = 3;
     int b = 5;

     cout << "max ->" << max(a,b) << endl;
     cout << "min ->" << min(a,b) << endl;

      cout << a<< b << endl;

     swap(a,b);

     cout << a<< b << endl;

    string s = "abcd";
    reverse(s.begin(), s.end());
    cout << "string -> " << s << endl;

    rotate(v.begin(), v.begin() +1, v.end());
    cout << "at=fter rotate " << endl;

    for(int i:v){
        cout << i << " ";
    }
   
}
