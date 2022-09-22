#include <iostream>

using namespace std;

struct A {
    virtual void fun() {
        cout << "A::fun()" << endl;
    }
    void gun(){
        cout << "A::fun()" << endl;
    }
};

struct B : public A {
    void fun() {
        cout << "B::fun()" << endl;
    }
    void gun(){
        cout << "B::fun()" << endl;
    }
};

struct C : public B {
    void fun() {
        cout << "C::fun()" << endl;
    }
    virtual void gun(){
        cout << "C::fun()" << endl;
    }
};


struct D : public C {
    void fun() {
        cout << "D::fun()" << endl;
    }
    void gun(){
        cout << "D::fun()" << endl;
    }
};

int main() {
    C *p = new D;
    p->gun();
}
