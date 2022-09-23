#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

void print(int &number){ // pure function
    cout << "number: " << number << endl;
}

bool isOdd(int number){
    return number & 1;
}

int main() {
    int numbers[]{4, 8, 15, 16, 23, 42};
    int size = sizeof(numbers) / sizeof(int);
    int sum = 0;

    // Loop #1 : outer loop
    for (auto i = 0; i < size; ++i) {
        int number = numbers[i];
        if (number & 1) {
            sum = sum + number * number;
        }
    }

    cout << "sum: " << sum << endl;

    // Loop #2 : outer loop
    sum = 0;
    for (auto& number : numbers) { // safe
        if (number & 1) {
            sum = sum + number * number;
        }
    }
    cout << "sum: " << sum << endl;

    // Loop #3 : inner loop
    // Functional Programming : c++11
    // 1. higher-order function
    // 2. pure function
    // auto numOfOdds = count_if(numbers,numbers+size,isOdd); // higher-order function
    int state = 42;
    auto numOfOdds = accumulate(numbers,numbers+size,int(),
       [](int acc, int &value)
       {
        if (value & 1)
          return acc + value * value;
        return acc;
       }
     ); // higher-order function
    cout << "number of odds: " << numOfOdds << endl;

    return 0;
}