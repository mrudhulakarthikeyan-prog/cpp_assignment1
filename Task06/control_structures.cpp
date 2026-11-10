#include <iostream>
#include <iomanip>

enum class Zone { Inner, Middle, Outer };
constexpr long long BASE_PAISE[] = {1000, 2000, 3000};
constexpr int PEAK_SURCHARGE_PERCENT = 20;
constexpr long long MIN_BALANCE_PAISE = 5000;

bool isPeakHour(int hour) {
    return (hour >= 8 && hour < 10) || (hour >= 17 && hour < 20);
}

long long fare(Zone zone, bool peak) {
    long long base = 0;
    switch (zone) {
        case Zone::Inner: base = BASE_PAISE[0]; break;
        case Zone::Middle: base = BASE_PAISE[1]; break;
        case Zone::Outer: base = BASE_PAISE[2]; break;
        default: return 0;
    }
    if (peak) base += base * PEAK_SURCHARGE_PERCENT / 100;
    return base;
}

bool canTravel(long long balance, long long amount) {
    return amount >= 0 && balance - amount >= MIN_BALANCE_PAISE;
}

int main() {
    struct Trip { Zone zone; bool peak; };
    const Trip trips[] = {
        {Zone::Inner, false}, {Zone::Outer, true}, {Zone::Middle, false}
    };

    long long balance = 10000;
    for (const Trip& trip : trips) {
        const long long amount = fare(trip.zone, trip.peak);
        if (canTravel(balance, amount)) {
            balance -= amount;
            std::cout << "Fare Rs " << amount / 100 << '.'
                      << std::setw(2) << std::setfill('0') << amount % 100
                      << std::setfill(' ') << " balance Rs " << balance / 100 << '\n';
        } else {
            std::cout << "Denied (low balance) balance Rs " << balance / 100 << '\n';
        }
    }

    std::cout << std::boolalpha
              << "10:00 peak? " << isPeakHour(10) << '\n'
              << "20:00 peak? " << isPeakHour(20) << '\n';
}
