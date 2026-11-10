#include <iostream>
#include <array>
#include <string>

enum class Zone { Inner, Middle, Outer, Airport };
constexpr std::array<long long, 4> FARES = {1000, 2000, 3000, 6000};
constexpr long long MIN_BALANCE = 5000;

class MonthlyPass {
private:
    Zone first_;
    Zone second_;
    bool active_;

public:
    MonthlyPass(Zone first, Zone second)
        : first_(first), second_(second), active_(true) {}

    bool covers(Zone zone) const {
        return active_ && (zone == first_ || zone == second_);
    }
};

class SmartCard {
private:
    long long balancePaise_;

public:
    explicit SmartCard(long long balance) : balancePaise_(balance) {}

    bool pay(long long farePaise) {
        if (farePaise < 0 || balancePaise_ - farePaise < MIN_BALANCE) return false;
        balancePaise_ -= farePaise;
        return true;
    }

    long long balance() const { return balancePaise_; }
};

long long calculateFare(Zone zone, bool peak, bool weekend) {
    const auto index = static_cast<std::size_t>(zone);
    if (index >= FARES.size()) return -1;

    const long long base = FARES[index];

    // Weekend discount replaces peak surcharge; the two do not combine.
    if (weekend) return base - (base * 10) / 100;
    if (peak) return base + (base * 20) / 100;
    return base;
}

const char* zoneName(Zone zone) {
    switch (zone) {
        case Zone::Inner: return "Inner";
        case Zone::Middle: return "Middle";
        case Zone::Outer: return "Outer";
        case Zone::Airport: return "Airport";
    }
    return "Unknown";
}

int main() {
    SmartCard card(20000);
    MonthlyPass pass(Zone::Inner, Zone::Middle);

    const Zone journeys[] = {Zone::Airport, Zone::Outer, Zone::Inner};
    const bool peak[] = {true, true, false};
    const bool weekend[] = {false, true, true};

    std::cout << "REVISED METRO FARE SYSTEM\n";
    for (std::size_t i = 0; i < 3; ++i) {
        const Zone zone = journeys[i];
        std::cout << "\nZone: " << zoneName(zone) << '\n';

        if (pass.covers(zone)) {
            std::cout << "Monthly pass: JOURNEY COVERED (no fare deducted)\n";
            continue;
        }

        const long long amount = calculateFare(zone, peak[i], weekend[i]);
        std::cout << "Fare paise: " << amount << '\n';
        std::cout << "Weekend discount: " << (weekend[i] ? "Yes" : "No")
                  << " | Peak period: " << (peak[i] ? "Yes" : "No") << '\n';
        std::cout << "Payment: " << (card.pay(amount) ? "APPROVED" : "DENIED") << '\n';
        std::cout << "Balance paise: " << card.balance() << '\n';
    }
}
