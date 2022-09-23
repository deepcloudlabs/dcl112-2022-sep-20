#include <iostream>
#include <list>
#include <ranges>
#include <algorithm>

using namespace std;

int main() {
    list<int> numbers{4, 7, 15, 16, 23, 42};
    list<int> odd_numbers;
    // 1. for-each-loop
    for (auto &number: numbers) {
        if (number & 1) {
            auto cubed = number * number * number;
            // cout << "cubed: " << cubed << endl;
        }
    }

    // 2. stl -> parallel/algorithm -> functional programming
    auto isOdd = [](auto &number) {
        cerr << "isOdd(" << number << ")" << endl;
        return number & 1;
    };
    auto toCube = [](auto &number) {
        cerr << "toCube(" << number << ")" << endl;
        return number * number * number;
    };
    auto print = [](auto &number) { cout << "cubed: " << number << endl; };
    //  i) higher-order functions: copy_if, transform, for_each
    // ii) pure function -> lambda expression
    /*
    copy_if  (numbers.begin()    ,numbers.end()    , back_inserter(odd_numbers),isOdd);
    transform(odd_numbers.begin(),odd_numbers.end(),odd_numbers.begin(),toCube);
    for_each (odd_numbers.begin(),odd_numbers.end(),print);
    */
    // 3. ranges -> stl/container
    // 1-PASS
    for (auto number: numbers | std::ranges::views::filter(isOdd)
                              | std::ranges::views::transform(toCube)
            ) {
        cerr << "cubed: " << number << endl;
    }
    // reactive programming
    // https://reactivex.io/
    // https://github.com/ReactiveX/RxCpp
    return 0;
}
