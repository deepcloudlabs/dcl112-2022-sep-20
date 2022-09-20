#include <iostream>

int main() {
    int a = 0, b, c = 42; // local/temporary/automatic/stack variable
    a++; // post-increment/decrement -> 1
    ++a; // pre-increment/decrement  -> 2
    // b = a++ + ++c;
    int t = a;
    c = c + 1;
    a = a + 1;
    b = t + c;

    b = ++a + c++; // b = 4, a=4
    for (int i = 0; i < 100; ++i) {
        int x = 12; // x is a stack variable, automatically (100 times) created/destroyed

    } // x is destroyed
    // i is destroyed!
    return 0;
}
