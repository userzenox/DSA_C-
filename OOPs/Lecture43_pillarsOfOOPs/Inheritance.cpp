#include<iostream>
using namespace std;

class Human {
public:
   
    int age;
    int weight;
protected:    
    int height=5.8;
   

public:
    int getAge() {
        return this->age;
    }
    void setWeight(int w) {
        this->weight = w;
    }
};

class Male: public Human {

    public: 
    string colour;

    void sleep(){
        cout << "Male sleeping" << endl;
    }
    int getheight(){
        return  height;
    }
};

int main() {

    Male object1;
    cout << object1.age << endl;
    cout << object1.colour << endl;
    cout << object1.weight << endl;

    object1.setWeight(60);
    cout << object1.weight << endl;
    cout << object1.getheight() << endl;

    
    return 0;
}