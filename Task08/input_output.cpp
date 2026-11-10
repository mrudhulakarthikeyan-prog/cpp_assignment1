#include <iostream>
#include <iomanip>
#include <limits>

int main() {
    int zone = 0;
    int hour = 0;

    std::cout << "Enter zone (1=Inner, 2=Middle, 3=Outer): ";
    if (!(std::cin >> zone)) {
        std::cout << "Invalid zone input. Please enter a number.\n";
        return 1;
    }

    std::cout << "Enter hour (0-23): ";
    if (!(std::cin >> hour)) {
        std::cout << "Invalid hour input. Please enter a number.\n";
        return 1;
    }

    if (zone < 1 || zone > 3 || hour < 0 || hour > 23) {
        std::cout << "Input out of range.\n";
        return 1;
    }

    const long long base[] = {0, 1000, 2000, 3000};
    long long fare = base[zone];
    const bool peak = (hour >= 8 && hour < 10) || (hour >= 17 && hour < 20);
    if (peak) fare += fare * 20 / 100;

    std::cout << std::fixed << std::setprecision(2)
              << "Peak hour: " << std::boolalpha << peak << '\n'
              << "Fare: Rs " << fare / 100.0 << '\n';
}
