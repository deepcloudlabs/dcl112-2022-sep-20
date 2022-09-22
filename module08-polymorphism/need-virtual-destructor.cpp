#include <iostream>

using namespace std;

struct A {
    A(){
        cout << "A::A()" << endl;
    }
    virtual void fun(){

    }
    virtual ~A(){
        cout << "A::~A()" << endl;
    }
};

struct B : public A {
    B(){
        cout << "B::B()" << endl;
    }
    ~B(){
        cout << "B::~B()" << endl;
    }
};
int main(){
    A *p = new B;
    delete p;
    return 0;
}