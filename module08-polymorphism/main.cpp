#include <iostream>
class I {
public:
    I() = delete;
    I(const I& ref) = delete;
    virtual void fun() =0;
    virtual int gun() =0;
};
using namespace std;
class Shape { // abstract class
public:
    virtual double area() =0 ; // pure virtual -> abstract method
};
// VT (Virtual Table):
// Square::area
class Square : public Shape{
protected:
    double edge;
public:
    Square(double e) : edge(e) {}

    double area() { return (edge * edge); }
};

// VT:
// Cube::area
class Cube : public Shape { // (1)
protected:
    double edge;
public:
    Cube(const double edge) : edge(edge) {}

    double area() {
        return (6.0 * edge * edge);
    }
};

int main() {
    cout << sizeof(double) << endl;
    cout << sizeof(Square) << endl;
    cout << sizeof(Cube) << endl;

    Square S(2.0);
    Cube C(2.0);
    Shape *ptr; // (2)
    char c;
    cout << "Square or Cube";
    cin >> c;
    if (c == 's')
        ptr = &S;
    else
        ptr = &C;
    cout << "Area: " << ptr->area() << endl;
    return 0;
}
