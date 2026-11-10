#include <iostream>
#include <array>
#include <string>

enum class Zone { Inner, Middle, Outer };
constexpr std::array<long long, 3> FARES = {1000, 2000, 3000};
constexpr long long MIN_BALANCE = 5000;

bool isPeak(int hour) {
    return (hour >= 8 && hour < 10) || (hour >= 17 && hour < 20);
}
long long calculateFare(Zone zone, int hour) {
    const auto index = static_cast<std::size_t>(zone);
    if (index >= FARES.size() || hour < 0 || hour > 23) return -1;
    long long result = FARES[index];
    if (isPeak(hour)) result += result * 20 / 100;
    return result;
}
class SmartCard {
    long long balance_;
public:
    explicit SmartCard(long long initial) : balance_(initial) {}
    bool pay(long long fare) {
        if (fare < 0 || balance_ - fare < MIN_BALANCE) return false;
        balance_ -= fare;
        return true;
    }
    long long balance() const { return balance_; }
};
int main() {
    SmartCard card(10000);
    const long long amount = calculateFare(Zone::Outer, 18);
    std::cout << "Recommended design: enum class, constexpr fare table, "
                 "integer paise and private SmartCard balance.\n";
    std::cout << "Calculated fare paise: " << amount << '\n';
    std::cout << "Payment: " << (card.pay(amount) ? "APPROVED" : "DENIED") << '\n';
    std::cout << "Remaining balance paise: " << card.balance() << '\n';
}
