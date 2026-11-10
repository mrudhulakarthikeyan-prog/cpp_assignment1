#include <iostream>
#include <vector>
#include <string>

enum class Zone { Inner, Middle, Outer };
long long fare(Zone z, int hour) {
    long long amount = z == Zone::Inner ? 1000 :
                       z == Zone::Middle ? 2000 : 3000;
    const bool peak = (hour >= 8 && hour < 10) || (hour >= 17 && hour < 20);
    return peak ? amount + amount * 20 / 100 : amount;
}
bool canTravel(long long balance, long long amount) {
    return amount >= 0 && balance - amount >= 5000;
}
int main() {
    struct Test { std::string name; Zone zone; int hour; long long expected; };
    const std::vector<Test> tests = {
        {"Inner off-peak", Zone::Inner, 11, 1000},
        {"Inner at 08:00", Zone::Inner, 8, 1200},
        {"Middle at 10:00", Zone::Middle, 10, 2000},
        {"Outer at 17:00", Zone::Outer, 17, 3600},
        {"Outer at 20:00", Zone::Outer, 20, 3000}
    };

    std::cout << "TEST CASES\n";
    for (const auto& test : tests) {
        const long long actual = fare(test.zone, test.hour);
        std::cout << test.name << " | expected " << test.expected
                  << " | actual " << actual
                  << " | " << (actual == test.expected ? "PASS" : "FAIL") << '\n';
    }

    std::cout << "\nExact minimum-balance boundary: "
              << (canTravel(6200, 1200) ? "ACCEPT" : "DENY") << '\n';
    std::cout << "One-paise-below boundary: "
              << (canTravel(6199, 1200) ? "ACCEPT" : "DENY") << '\n';
}
