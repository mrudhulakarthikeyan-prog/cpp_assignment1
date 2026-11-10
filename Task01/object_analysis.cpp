#include <iostream>
#include <string>

enum class Zone { Inner, Middle, Outer };

class Passenger {
private:
    std::string name_;
    std::string category_;

public:
    Passenger(std::string name, std::string category)
        : name_(std::move(name)), category_(std::move(category)) {}

    void display() const {
        std::cout << "Passenger: " << name_ << "\nCategory: " << category_ << '\n';
    }
};

class FareTable {
public:
    static long long baseFarePaise(Zone zone) {
        switch (zone) {
            case Zone::Inner: return 1000;
            case Zone::Middle: return 2000;
            case Zone::Outer: return 3000;
        }
        return 0;
    }
};

class Journey {
private:
    Zone destination_;
    bool peak_;

public:
    Journey(Zone destination, bool peak) : destination_(destination), peak_(peak) {}
    long long farePaise() const {
        const long long base = FareTable::baseFarePaise(destination_);
        return peak_ ? base + (base * 20) / 100 : base;
    }
    void display() const {
        const char* zoneName = destination_ == Zone::Inner ? "Inner" :
                               destination_ == Zone::Middle ? "Middle" : "Outer";
        std::cout << "Destination: " << zoneName
                  << "\nPeak hour: " << (peak_ ? "Yes" : "No") << '\n';
    }
};

class SmartCard {
private:
    long long balancePaise_;
    static constexpr long long minimumBalancePaise_ = 5000;

public:
    explicit SmartCard(long long initialBalancePaise) : balancePaise_(initialBalancePaise) {}

    bool canTravel(long long farePaise) const {
        return farePaise >= 0 && balancePaise_ - farePaise >= minimumBalancePaise_;
    }
    bool deduct(long long farePaise) {
        if (!canTravel(farePaise)) return false;
        balancePaise_ -= farePaise;
        return true;
    }
    long long balancePaise() const { return balancePaise_; }
};

int main() {
    Passenger passenger("Arun", "Regular");
    SmartCard card(10000);
    Journey first(Zone::Outer, true);
    Journey second(Zone::Middle, false);

    std::cout << "NAMMA METRO SMART-CARD SYSTEM\n";
    passenger.display();

    for (int i = 1; i <= 2; ++i) {
        const Journey& journey = (i == 1) ? first : second;
        const long long fare = journey.farePaise();
        std::cout << "\nJourney " << i << '\n';
        journey.display();
        std::cout << "Fare: Rs " << fare / 100 << '.'
                  << (fare % 100 < 10 ? "0" : "") << fare % 100 << '\n';
        std::cout << "Status: " << (card.deduct(fare) ? "APPROVED" : "DENIED") << '\n';
        std::cout << "Balance: Rs " << card.balancePaise() / 100 << '\n';
    }
}
