#include "Ticket.h"

Ticket::Ticket(Match* match, const std::string& seatNumber, double price)
    : match(match), seatNumber(seatNumber), price(price), available(true) {}

Match* Ticket::getMatch() const {
    return match;
}

void Ticket::setMatch(Match* match) {
    this->match = match;
}

std::string Ticket::getSeatNumber() const {
    return seatNumber;
}

void Ticket::setSeatNumber(const std::string& seatNumber) {
    this->seatNumber = seatNumber;
}

double Ticket::getPrice() const {
    return price;
}

void Ticket::setPrice(double price) {
    this->price = price;
}

bool Ticket::isAvailable() const {
    return available;
}

void Ticket::setAvailability(bool available) {
    this->available = available;
}