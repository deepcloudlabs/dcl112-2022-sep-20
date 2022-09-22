#include <iostream>

using namespace std;

// 1. Default Constructor
// 2. Copy Constructor
// 3. Destructor
// 4. Assignment Operator
class B {
};


class A {
public:
    int *p;

    A(int value) {
        p = new int{value};
    }

    A(const A &other) { // copy constructor
        int value = *other.p;
        p = new int{value};
    }

    ~A() {
        delete p;
    }
};

// 1. Copy Constructor -> Shallow Copy
// 2. Destructor
// 3. Assignment Operator -> Shallow Copy
class D {
public:
    int x;

    D(int x) : x(x) {
        cout << "D(int x)" << endl;
    }

    D(const D &other) : x(other.x) {
        cout << "D(const D &other)" << endl;
    }

    D(const A &other) : x(*(other.p)) {
        cout << "D(const A &other)" << endl;
    }

    ~D() {
        cout << "~D()" << endl;
    }

    D &operator=(const D &other) {
        cout << "operator=(const D &other)" << endl;
        this->x = other.x;
        return *this;
    }

    D &operator=(const A &other) {
        cout << "operator=(const D &other)" << endl;
        this->x = *(other.p);
        return *this;
    }

    D &operator=(int x) {
        cout << "operator=(const D &other)" << endl;
        this->x = x;
        return *this;
    }

    D operator+(const D &other) {
        D result(this->x + other.x); // stack
        return result;
    }

};

int main() {
    D d1(42);  // D(int x)
    D d2{42};  // D(int x)
    D d6 = d1 + d2;
    cout << "d6.x: " << d6.x << endl;
    D d3 = 42; // D(int x) requires explicit initialization
    D d4 = d2; // D(const D &other)
    D d5(d2);  // D(const D &other)
    D d7{d2};  // D(const D &other)
    d2 = d4; // operator=(const D &other)
    d1 = d2 = d3; // method chaining
    d2 = d3;
    d1 = d2;
    d1 = 44;
    return 0;
}
