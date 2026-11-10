#include <iostream>

constexpr long long MIN_BALANCE = 5000;

long long calculateFare(int zone, bool peak) {
    long long amount = (zone == 1 ? 1000 : zone == 2 ? 2000 : zone == 3 ? 3000 : 0);
    if (peak) amount += amount * 20 / 100;
    return amount;
}

bool canTravel(long long balance, long long amount) {
    return amount > 0 && balance - amount >= MIN_BALANCE;
}

int main() {
    long long balance = 10000;
    const long long amount = calculateFare(3, true);
    if (canTravel(balance, amount)) {
        balance -= amount;
        std::cout << "APPROVED\n";
    } else {
        std::cout << "DENIED\n";
    }
    std::cout << "Balance paise: " << balance << '\n';
}
