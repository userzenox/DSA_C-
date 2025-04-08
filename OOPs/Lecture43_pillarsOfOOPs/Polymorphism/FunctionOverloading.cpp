#include<iostream>
using namespace std;

// Function overload
class A {
public:
    void sayHello() {
        cout << "Hello Love Babbar" << endl;
    }

    void sayHello(string name) {
        cout << "Hello " << name << endl;
    }

    void sayHello(int n) {
        cout << "Hello " << n << endl;
    }
};

int main() {
    A obj;
    obj.sayHello();
    obj.sayHello("string");
    obj.sayHello(4);

    return 0;
}