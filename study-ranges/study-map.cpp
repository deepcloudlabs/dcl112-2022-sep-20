#include <map>
#include <iostream>
#include <string>

using namespace std;

int main() {
    map<string, int> areaCodes;

    areaCodes.insert({"istanbul-anadolu", 216});
    areaCodes.insert({"istanbul-avrupa", 212});
    areaCodes.insert({"ankara", 312});

    // since c++11
    for (const auto &areaCode: areaCodes) {
        cout << areaCode.first << ": " << areaCode.second << endl;
    }

    // since c++17
    for (const auto &[city, code]: areaCodes) {
        cout << city << ": " << code << endl;
    }


    return 0;
}