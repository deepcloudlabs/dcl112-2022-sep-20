#include <iostream>

using namespace std;

class A {
protected:
    int *p;
public:
    A() {
        cout << "A::A()" << endl;
        p = new int(42);
    }

    ~A() {
        cout << "A::~A()" << endl;
        delete p;
    }
};

class B : public A {
    int *q;
public:
    B() {
        cout << "B::B()" << endl;
        q = new int(42);
    }

    ~B() {
        cout << "B::~B()" << endl;
        *p++;
        delete q;
    }

};

int main() {
    A *p = new A();
    {
        A a;
        // trigger A's destructor
    }
    delete p; // trigger A's destructor

    // there is no "a"
    B b;

    return 0;
}