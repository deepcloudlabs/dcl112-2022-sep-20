#include <iostream>
#include <cstring>

using namespace std;

// 1. call-by-value
void call_swap(int x, int y) { // x = 3, y = 5 are at the stack
    int temp = x;
    x = y;
    y = temp;
    // x = 5, y = 3
}

// 2. call-by-pointer
void swap(int *x, int *y) { // x = 3, y = 5 are at the stack
    int temp = *x;
    *x = *y;
    *y = temp;
}

// 3. call-by-reference
void swap(int &x, int &y) { // x = 3, y = 5 are at the stack
    int temp = x;
    x = y;
    y = temp;
}

// call by value -> read-only
int sum(int array[], int size) {
    int total = 0;
    for (int i = 0; i < size; ++i)
        total += array[i];
    return total;
}

struct Person {
    char name[40];
    int identity;
};

// constant reference
void print(const Person &k) { // 4 Byte/8 Byte
    cout << "Name: " << k.name << endl;
    // Not allowed: strcpy(k.name, "Jack Bauer");
    // Not allowed: k.identity = 1;
    cout << "Num: " << k.identity << endl;
}

int &f() { // Danger!
    int i = 42;
    return i;
}

int main() {
    int u = 3, v = 5;
    cout << "u=" << u
         << ",v=" << v << endl;
    swap(u, v);
    cout << "u=" << u
         << ",v=" << v << endl;
    int &w = f(); // Problem!
    cout << "w=" << w << endl;
    return 0;
}