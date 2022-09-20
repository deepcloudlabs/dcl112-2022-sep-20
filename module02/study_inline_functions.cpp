#include <cstdint>
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;
#define sq(x) ((x)*(x)) // macro

// readable
inline double inlined_square(double x) { // type-check
    return x * x * x; // debug
}

double square(double x) { // type-check
    return x * x * x; // debug
}

int main() {
    int a = 42, b = 108;
    int z = square(a + b); // int z = (a+b)*(a+b);
    int32_t x = 64;
    int64_t y = 108;
    // simd -> vector operations
    // -O3
    {
        auto begin = steady_clock::now();
        auto sum = 0;
        for (auto i = 0; i < 500'000'000; ++i) {
            inlined_square(i);
        }
        auto end = steady_clock::now();
        cout << "sum: " << sum << endl;
        cout << "Time difference = " << duration_cast<std::chrono::microseconds>(end - begin).count() << "[microsecond]"
             << endl;
        cout << "Time difference = " << duration_cast<std::chrono::nanoseconds>(end - begin).count() << "[nanosecond]"
             << endl;
    }
    {
        auto sum = 0;
        auto begin = steady_clock::now();
        for (auto i = 0; i < 500'000'000; ++i) {
            square(i);
        }
        auto end = steady_clock::now();
        cout << "sum: " << sum << endl;
        cout << "Time difference = " << duration_cast<std::chrono::microseconds>(end - begin).count() << "[microsecond]"
             << endl;
        cout << "Time difference = " << duration_cast<std::chrono::nanoseconds>(end - begin).count() << "[nanosecond]"
             << endl;
    }
}
// object?
// 1. stack -> stack size -> stackoverflow
// 2. heap -> new/delete -> library

// class->object, primitive types
// data -> cache

