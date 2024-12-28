#include "Seat.h"
#include <iostream>

Seat::Seat(int n) : num(n) {}

int Seat::getNum() const {
    return num;
}

void Seat::setNum(int n) {
    num = n;
}

bool Seat::isEmpty() const {
    return empty;
}

void Seat::setEmpty(bool e) {
    empty = e;
}

SeatType Seat::getType() const {
    if(num >= 1 && num <= 500) {
        return SeatType::VIP;
    }
    else {
        return SeatType::Regular;
    }
}

void Seat::setType(SeatType t) {
    type = t;
}

void Seat::displaySeat() const {
    std::cout << "Seat Number: " << num << ", Type: " << (type == SeatType::VIP ? "VIP" : "Regular") << std::endl;
}

void Seat::inputSeat() {
    std::cout << "Enter seat type (0 - VIP, 1 - Regular): ";
    int t;
    std::cin >> t;
    type = static_cast<SeatType>(t);
    std::cout << "Enter seat number: ";
    std::cin >> num;
}
