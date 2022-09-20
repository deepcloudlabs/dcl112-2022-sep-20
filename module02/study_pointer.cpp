#include <cmath>
#include <iostream>

using namespace std;

struct circle {
    double x, y, radius;
};

circle c2{10.0, 10.0, 20.0}; // data

int main() {
    circle c1{0.0, 0.0, 100.0}; // stack
    circle &c3 = c1;
    double alan = M_PI * c3.radius * c3.radius;
    cout << "Area is " << alan << endl;
    circle *p1; // stack, pointer holds address
    p1 = &c2;
    // p2 is a pointer at the stack
    circle *p2 = new circle{0, 0, 10}; // heap
    double area = M_PI * p2->radius * p2->radius;
    area = M_PI * (*p2).radius * (*p2).radius;
    area = M_PI * p2[0].radius * p2[0].radius;
    cout << "Area is " << area << endl;
    circle **p3 = new circle *[10]; // array of pointers
    for (int i = 0; i < 10; ++i)
        p3[i] = new circle{0, 0, (i + 1) * 10.0};

    area = M_PI * p3[9]->radius * p3[9]->radius;
    cout << "Area is " << area << endl;

    for (int i = 0; i < 10; ++i)
        delete p3[i];
    delete[] p3;

    return 0;
}
