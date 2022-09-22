#include <iostream>

using namespace std;

struct A {
    // public
    int x;
private:

};

class B {
    // private
public:
    int x;
};

class D {
    int x;
public:
    explicit D(int x) : x(x) {}

    D(const D &other) = delete; // since c++11
    void operator=(const D &other) = delete; // since c++11
    int getX() const {
        return x;
    }
};

int main() {
    D d1{42};
    // D d2(d1); // Error: copy constructor is deleted.
    // D d3(d1); // Error: copy constructor is deleted.
    // d3 = d2;  // Error: assignment operator is deleted.
    cout << "d1.getX(): " << d1.getX() << endl;
    // cout << "d2.getX(): " << d2.getX() << endl;
    return 0;
}