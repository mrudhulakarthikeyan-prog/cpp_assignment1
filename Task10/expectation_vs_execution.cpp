#include <iostream>
#include <iomanip>

int main() {
    constexpr long long journeys[] = {20000LL, 500000LL, 3000000LL};
    constexpr long long farePaise = 3000LL; // example: Rs 30 per journey

    std::cout << "JOURNEY TOTAL COMPARISON (Rs 30 per journey)\n";
    for (long long count : journeys) {
        const long long exactPaise = count * farePaise;
        const double rupees = static_cast<double>(count) * 30.0;
        std::cout << "Journeys: " << count
                  << " | integer-paise total: Rs " << exactPaise / 100
                  << " | double total: Rs " << std::fixed << std::setprecision(2)
                  << rupees << '\n';
    }

    const long long networkTotal = journeys[2] * farePaise;
    std::cout << "3,000,000 journey total in paise: " << networkTotal << '\n';
    std::cout << "INT_MAX: " << 2147483647 << '\n';
    std::cout << "The total paise value exceeds the range of a typical 32-bit int; "
                 "use long long.\n";
}
