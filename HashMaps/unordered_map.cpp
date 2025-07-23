#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main() {

    //creation
    unordered_map<string,int> m;

    //insertion

    //.1
    pair<string,int> p1 = make_pair("babber" , 3);
     m.insert(p1);

     //.2
     pair<string,int> p2("quuen", 2);
      m.insert(p2);

     //.3
     m["cyan"] = 1;
     m["cyan"] = 2;

     cout << m["cyan"] << endl;

    //  cout << m.at("sjbdh") << endl;
     

     cout << m["sjbdh"]  << endl;
     cout << m.at("sjbdh") << endl;

     cout << m["wuehu"] << endl;
       cout << m.at("sjbdh") << endl;

       cout << "size " << m.size() << endl; 
    return 0;
}