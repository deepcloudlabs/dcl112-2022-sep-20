#include <iostream>

using namespace std;

// Global variables -> Data
// Process' Memory Model: Stack, Heap, Data, Text
int x = 42; // scalar -> single value
int y = 108;

int numbers[] = {4, 8, 15, 16, 23, 42}; // global -> data, array -> 6 values

// values is a pointer in Data section holds an address
// the address points to an array in Heap
int *values = new int[6]{4, 8, 15, 16, 23, 42};
// values [ address of (4) ] ---> [(4) 8 15 16 23 42]

int fun(); // declaration
void gun();

int main() { // declaration + definition -> text
    fun();
    cout << "x: " << x << endl; // 43
    cout << "y: " << y << endl; // 109
}

void gun() {
    // values is a pointer in Stack holds an address
    // the address points to an array in Heap
    int *values = new int32_t[6]{4, 8, 15, 16, 23, 42}; // allocates an array of 6 integers -> 24B
    // sizeof(int) -> portable, pointer arithmetics
    // delete []values; // dis-allocates the array --> MEMORY LEAK, Memory Footprint
} // values is destroyed!

int fun() { // definition -> text
    int x = 549; // x is created at the stack, hides global x
    x++; // increments local x -> 550
    ::x++; // increments global x -> 43
    y++; // increments global y -> 109
    return x + y;
} // x is destroyed!