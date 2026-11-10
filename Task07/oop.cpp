#include <iostream>

class SmartCard {
private:
    long long balancePaise_;
    static constexpr long long minimumPaise_ = 5000;

public:
    explicit SmartCard(long long initial) : balancePaise_(initial) {}

    bool canTravel(long long farePaise) const {
        return farePaise >= 0 && balancePaise_ - farePaise >= minimumPaise_;
    }

    bool deduct(long long farePaise) {
        if (!canTravel(farePaise)) return false;
        balancePaise_ -= farePaise;
        return true;
    }

    long long balance() const { return balancePaise_; }
};

int main() {
    SmartCard card(10000);
    const long long fare = 3600;
    std::cout << (card.deduct(fare) ? "APPROVED" : "DENIED") << '\n';
    std::cout << "Balance paise: " << card.balance() << '\n';
}
